#include "game.h" 
#include "util.h"

char tempMap[14][56];

char map1[14][56] = {
	{"1111111111111111111111111111111111111111111111111111111"},  
	{"1000000010000000000000000000000000000000000000000000001"},
	{"1000000010000000000000000000000000000000000000000000001"}, 
	{"1000100010000000000000000000000000000000000000000000001"}, 
	{"1000100010000000000000000000000000000000000000000000001"}, 
	{"1000100010000000000000000000000000000000000000000000001"}, 
	{"1000100011111100000000000000000000000000000000000000001"},  
	{"1000100000000100000000000000000000000000000000000000001"},
	{"1000100010000100000000000000000000000000000000000000001"},
	{"10001000100k0100000000000000000000000000000000001111111"},
	{"1000100010000100000000000000000000000000000000001000001"},
	{"10s010001111111111111111111111111111111111111111100q001"},
	{"10001000l0000000000000000000000000000000000000000000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};

char map2[14][56] = { 
	{"1111111111111111111111111111111111111111111111111111111"}, 
	{"100000100010001k000100000000001000100000100010100010001"},
	{"1000001010101011110101111101101010101110101010101000101"},
	{"1000101010001000k10101000101k01010101k10101000111111101"},
	{"1000100010111111110101010101111000100010101111100000001"},
	{"100011111l100000000101010100000001110110101000101011111"},
	{"1000100000101111111101010111011100000010001010001010001"},
	{"1000101111101000000001010000000111011010100010100010001"},
	{"10001010000010000001010110111100000000101010101010001l1"},
	{"10001010111010000001000000000101011110101010101011111l1"},
	{"100010101k001000000111101111000100001010101010001000001"},
	{"10s010101111111110110010100001011110100010111110100q001"},
	{"1000100000l000l0001000100011110000001010100000001000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};

  
void drawMap(int* x, int* y){
	system("cls");
	int h, w; 
	
	for(h=0; h<14; h++){ 
		for(w=0; w<56; w++){  
			char temp = tempMap[h][w]; 
			if(temp == '0'){ 
				setColor(black, black);  
				printf(" "); 
			} else if(temp == '1') {
				setColor(white, white);  
				printf("#"); 
			} else if(temp == 's') {
				*x = w;  
				*y = h;
				setColor(cyan, black);  
				printf("@");
			} else if(temp == 'q') {
				setColor(lightgreen, black);    
				printf("O"); 
			} else if(temp == 'k') { 
				setColor(yellow, black);
				printf("*"); 
			} else if(temp == 'l') {
				setColor(brown, black);
				printf("+");
			}
		}
		printf("\n"); 
	}
	setColor(white, black);
} 

void gLoop(int mapCode){
	int x, y;
	int key = 0; 
	
	int playing = 1;
	
	if(mapCode == 0){
		memcpy(tempMap, map1, sizeof(tempMap));
	} else if(mapCode == 1){
		memcpy(tempMap, map2, sizeof(tempMap));
	} // else if()
	
	drawMap(&x, &y); 
	
	while(playing){
		drawUI(&x, &y, &key);
		
		switch(keyControl()){
			case UP:
				move(&x, &y, 0, -1, &key, &playing); 
				break;
				
			case DOWN:
				move(&x, &y, 0, 1, &key, &playing); 
				break;
				
			case RIGHT:
				move(&x, &y, 1, 0, &key, &playing); 
				break;
				
			case LEFT:
				move(&x, &y, -1, 0, &key, &playing);
				break;
				
			case SUBMIT:
				playing = 0; 
		} 
	}
	gotoxy(22, 8);
	printf("Game Clear!");
	Sleep(1500);
}

void move(int* x, int* y, int _x, int _y, int* key, int* playing){
	char mapObject = tempMap[*y + _y][*x + _x];
	setColor(white, black); 
	
	if(mapObject == '0') {
		gotoxy(*x, *y);
		printf(" "); 
		
		setColor(cyan, black);  
		gotoxy(*x + _x, *y + _y); 
		printf("@");
		
		*x += _x; 
		*y += _y;
	} else if(mapObject == 'k') { 
		*key += 1; 
		tempMap[*y + _y][*x + _x] = '0';
		gotoxy(*x + _x, *y + _y); 
		printf(" ");
	} else if(mapObject == 'l') {
		if(*key > 0){
			*key -= 1;
			tempMap[*y + _y][*x + _x] = '0'; 
			setColor(white, black);
			gotoxy(*x + _x, *y + _y);
			printf(" ");
		}
	} else if(mapObject == 'q') {
		*playing = 0; 
	}
} 

void drawUI(int* x, int* y, int* key){
	setColor(white, black);
	gotoxy(3, 16);
	printf("위치: %02d, %02d", *x, *y); 
	
	setColor(yellow, black);
	gotoxy(34, 16); 
	printf("열쇠: %d개", *key);
}


int keyControl(){
	char temp = getch();
	
	if(temp == 'w' || temp == 'W'){
		return UP;
	} else if(temp == 'a' || temp == 'A'){
		return LEFT;
	} else if(temp == 's' || temp == 'S'){
		return DOWN;
	} else if(temp == 'd' || temp == 'D'){
		return RIGHT;
	} else if(temp == ' '){ 
		return SUBMIT;
	}
}

void titleDraw(){
	printf("\n\n\n\n"); 
	printf("        #####    ###    ###    #    ####   ##### \n");
	printf("        #       #      #      # #   #   #  #     \n");
	printf("        ####    ####   #     #####  ####   ####  \n");
	printf("        #           #  #     #   #  #      #     \n");
	printf("        #####   ####    ###  #   #  #      ##### \n");
} 

int menuDraw(){
	int x = 24; 
	int y = 12;
	gotoxy(x-2, y);
	printf("> 게임시작");
	gotoxy(x, y+1);
	printf("게임정보");
	gotoxy(x, y+2);
	printf("  종료  ");
	while(1){ 
		int n = keyControl(); 
		switch(n){
			case UP: { 
				if(y > 12){ 
					gotoxy(x-2, y); 
					printf(" "); 
					gotoxy(x-2, --y); 
					printf(">");  
				}
				break;
			}
				
			case DOWN: { 
				if(y < 14) { 
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			
			case SUBMIT: {
				return y-12; 
			}
		}
	}
} 

int maplistDraw(){
	int x = 24;
	int y = 6;
	system("cls");
	printf("\n\n");
	printf("                      [ 맵 선택 ]\n\n");
	
	gotoxy(x-2, y);
	printf("> 쉬움");
	gotoxy(x, y+1);
	printf("어려움"); 
	gotoxy(x, y+2);
	printf("뒤로"); 
	
	while(1){  
		int n = keyControl(); 
		switch(n){
			case UP: { 
				if(y > 6){ 
					gotoxy(x-2, y);  
					printf(" ");
					gotoxy(x-2, --y); 
					printf(">"); 
				}
				break;
			}
				
			case DOWN: { 
				if(y < 9) { 
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			
			case SUBMIT: {
				return y-6; 
			}
		}
	}
}

void infoDraw(){
	system("cls");
	printf("\n\n");
	printf("                        [ 조작법 ]\n\n");
	printf("                    이동: W, A, S, D\n");
	printf("                    선택: 스페이스바\n\n\n\n\n\n\n");
	printf("      스페이스바를 누르면 메인화면으로 이동합니다.");
	
	while(1){
		if(keyControl() == SUBMIT){
			break;
		}
	}
}


