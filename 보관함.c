//搾楳奄 恥惟績

//獣娃聖 爽壱 益掻拭 拝獣拭 戚疑,因維 0

//鋼差庚 紫遂 掻 脊径拝呪 赤澗走 溌昔 0

//什傾球 廃 匝 廃匝 持失 (原走厳 拙穣)紗亀 穣 拙穣

//穣 陥錘 廃仮 持失 0

//恥硝 戚疑 0

//恥引 舌拭弘 中宜 葵 0

//搾楳徹 戚疑 薦廃 獄益 背薦 0

//貝是亀 繕箭

//		0000000000
//	  	   000
//0		00000000
//000000000000000000
//0	     00000000
//		
//printf("\t\t0000000000\n");
//printf("\t\t   000\n");
//printf("\t0	 00000000\n");
//printf("\t0000000000000000000\n");
//printf("\t0	  00000000ぱ\n");


#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include <process.h>
#include<stdlib.h>
#include<conio.h>

#define RIGHT 77  
#define UP 72  
#define DOWN 80 

//int a[30][175];
//int sum = 0;

unsigned _stdcall Thread_A(void* arg);

void Gotxy(int x, int y);

unsigned _stdcall 慎(void* arg);
unsigned _stdcall 析(void* arg);
unsigned _stdcall 戚(void* arg);
unsigned _stdcall 誌(void* arg);
unsigned _stdcall 紫(void* arg);
unsigned _stdcall 神(void* arg);
unsigned _stdcall 整(void* arg);
unsigned _stdcall 張(void* arg);
unsigned _stdcall 独(void* arg);
unsigned _stdcall 姥(void* arg);
unsigned _stdcall 淑(void* arg);
unsigned _stdcall 淑析(void* arg);
unsigned _stdcall 淑戚(void* arg);
unsigned _stdcall 淑誌(void* arg);
unsigned _stdcall 淑紫(void* arg);
unsigned _stdcall 淑神(void* arg);
unsigned _stdcall 淑整(void* arg);
unsigned _stdcall 淑張(void* arg);
unsigned _stdcall 淑独(void* arg);
unsigned _stdcall 淑姥(void* arg);
unsigned _stdcall 戚淑(void* arg);
unsigned _stdcall 戚淑析(void* arg);
unsigned _stdcall 戚淑戚(void* arg);
unsigned _stdcall 戚淑誌(void* arg);
unsigned _stdcall 戚淑紫(void* arg);
unsigned _stdcall 戚淑神(void* arg);
unsigned _stdcall 戚淑整(void* arg);
unsigned _stdcall 戚淑張(void* arg);
unsigned _stdcall 戚淑独(void* arg);
unsigned _stdcall 戚淑姥(void* arg);




//int main(void) {
//
//	int ar1, ar2;
//	int count = 0;
//	int countget = 0;
//	int key;
//	int on = 0;
//	int dow = 0;
//	int hekp = 0;
//
//
//	for (int i = 0; i < 30; i++) {
//		for (int j = 0; j < 175; j++) {
//			a[i][j] = 32;
//		}
//	}
//
//	// 戚板 是焼掘拭 紫遂
//	for (int a1 = 0; a1 < 14; a1++) {
//		a[10][17 - a1] = 48;
//	}// 戚板 是焼掘拭 紫遂
//	for (int a1 = 0; a1 < 3; a1++) {
//		a[11][12 - a1] = 48;
//	}
//	a[12][0] = 48;
//	for (int a1 = 0; a1 < 6; a1++) {
//		a[12][13 - a1] = 48;
//	}
//	for (int a1 = 0; a1 < 17; a1++) {
//		a[13][0 + a1] = 48;
//	}
//	a[14][0] = 48;
//	for (int a1 = 0; a1 < 6; a1++) {
//		a[14][13 - a1] = 48;
//	}
//	a[14][14] = 45;
//	a[14][15] = 45;
//
//
//	_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);//窒径 覗鍵闘 
//
//	_beginthreadex(NULL, 0, 慎, 0, 0, NULL);
//
//	while (1) {
//		key = 0;//段奄鉢
//
//		if (kbhit()) { //侯虞
//			key = getch(); //徹戚径
//			if (key == 224) {//徹 脊径
//				do { key = getch(); } while (key == 224);//徹 脊径獣 脊形
//				if (key == UP) {//是稽
//					on++;
//					if (a[0][10] == 48) {//戚疑薦廃
//						on--;
//						continue;
//					}
//					for (int i = 0; i < 30; i++) {//戚疑 肢薦
//						for (int j = 0; j < 175; j++) {
//							if (a[i][j] == 48 || a[i][j] == 45) {
//								a[i][j] = 32;
//							}
//						}
//					}
//					for (int a1 = 0; a1 < 14; a1++) {//是稽 臣虞姶
//						a[10 - on + dow][17 - a1] = 48;
//					}
//					for (int a1 = 0; a1 < 3; a1++) {
//						a[11 - on + dow][12 - a1] = 48;
//					}
//					a[12 - on + dow][0] = 48;
//					for (int a1 = 0; a1 < 6; a1++) {
//						a[12 - on + dow][13 - a1] = 48;
//					}
//					for (int a1 = 0; a1 < 17; a1++) {
//						a[13 - on + dow][0 + a1] = 48;
//					}
//					a[14 - on + dow][0] = 48;
//					for (int a1 = 0; a1 < 6; a1++) {
//						a[14 - on + dow][13 - a1] = 48;
//					}
//					a[14 - on + dow][14] = 45;
//					a[14 - on + dow][15] = 45;
//				}
//				if (key == DOWN) {//焼掘稽
//					dow++;
//					if (a[29][10] == 48) {//戚疑 薦廃 庚薦 
//						dow--;
//						continue;
//					}
//					for (int i = 0; i < 30; i++) {//戚疑 肢薦
//						for (int j = 0; j < 175; j++) {
//							if (a[i][j] == 48 || a[i][j] == 45) {
//								a[i][j] = 32;
//							}
//						}
//					}
//					for (int a1 = 0; a1 < 14; a1++) {//戚疑 級嬢逢
//						a[10 - on + dow][17 - a1] = 48;
//					}
//					for (int a1 = 0; a1 < 3; a1++) {
//						a[11 - on + dow][12 - a1] = 48;
//					}
//					a[12 - on + dow][0] = 48;
//					for (int a1 = 0; a1 < 6; a1++) {
//						a[12 - on + dow][13 - a1] = 48;
//					}
//					for (int a1 = 0; a1 < 17; a1++) {
//						a[13 - on + dow][0 + a1] = 48;
//					}
//					a[14 - on + dow][0] = 48;
//					for (int a1 = 0; a1 < 6; a1++) {
//						a[14 - on + dow][13 - a1] = 48;
//					}
//					a[14 - on + dow][14] = 45;
//					a[14 - on + dow][15] = 45;
//				}
//				if (key == RIGHT) {//庶奄
//					hekp = 0;
//					for (int i = 0; i < 30; i++) {
//						for (int j = 0; j < 175; j++) {
//							if (a[i][j] == 45) {
//								hekp++;
//								if (hekp == 2) {
//									a[i][j + 3] = 62;
//								}
//							}
//						}
//					}
//				}
//			}
//
//		}
//
//	}
//}
//unsigned _stdcall Thread_A(void* arg) {
//	//system("cls");
//	int wkd = rand() % 30;
//	int temp = 0;
//	int count = 0;
//	while (1) {
//		Sleep(200);//戚疑 繕旋 葵 せせせせせせせせせせせ
//	re:
//		wkd = rand() % 30;//舌蕉弘 沓棋
//		if (wkd <= 4) {//舌蕉弘 是帖 仙敗
//			goto re;
//		}
//		a[wkd][174] = 64;
//		for (int i = 0; i < 30; i++) {
//			for (int j = 0; j < 175; j++) {
//				if (a[i][j] == 64) {//舌蕉弘 戚疑
//					temp = a[i][j];
//					a[i][j] = a[i][j - 1];
//					a[i][j - 1] = temp;
//
//				}
//			}
//		}
//		for (int i = 0; i < 30; i++) {//恥硝 戚疑
//			for (int j = 0; j < 175; j++) {
//				if (a[i][j] == 62) {
//
//					count++;
//					if (count == 2) {
//						count = 0;
//						continue;
//					}
//					temp = a[i][j];
//					a[i][j] = a[i][j + 1];
//					a[i][j + 1] = temp;
//				}
//
//			}
//		}
//		for (int i = 0; i < 30; i++) {//繊呪
//			for (int j = 0; j < 175; j++) {
//				if (a[i][j] == 62 && a[i][j + 1] == 64) {
//					a[i][j] = 0;
//					a[i][j + 1] = 0;
//					sum++;
//				}
//			}
//		}
//		//for (int i = 0; i < 30; i++) {//曽戟抗
//		//	for (int j = 0; j < 175; j++) {
//		//		if (a[i][j] == 48 && a[i][j + 1] == 64|| a[i][j] == 45 && a[i][j + 1] == 64) {
//		//			for (int a12 = 0; a12 < 5; a12++) {
//		//				system("cls");
//		//				printf("GAME OVER\n繊呪 : %d\n", sum);
//		//				printf("%d段 及 曽戟 桔艦陥.",5-a12);
//		//				Sleep(1000);
//		//			}
//		//			exit(0);
//		//		}
//		//	}
//		//}
//
//	}
//}
//void Gotxy(int x, int y)//据馬澗 是帖拭 窒径馬澗 杯呪
//{
//	COORD Pos = { y - 1,x - 1 };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
//}
//unsigned _stdcall 慎(void* arg) {
//	while (1) {
//		Gotxy(1, 1);
//		for (int i = 0; i < 30; i++) {
//			for (int j = 0; j < 174; j++) {
//				printf("%c", a[0 + i][j]);
//			}
//			printf("\n");
//		}
//	}
//}
//unsigned _stdcall 析(void* arg) {
//	while (1) {
//		Gotxy(2, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[1][j]);
//		}
//	}
//}
//unsigned _stdcall 戚(void* arg) {
//	while (1) {
//		Gotxy(3, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[2][j]);
//		}
//	}
//}
//unsigned _stdcall 誌(void* arg) {
//	while (1) {
//		Gotxy(4, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[3][j]);
//		}
//	}
//}
//unsigned _stdcall 紫(void* arg) {
//	while (1) {
//		Gotxy(5, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[4][j]);
//		}
//	}
//}
//unsigned _stdcall 神(void* arg) {
//	while (1) {
//		Gotxy(6, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[5][j]);
//		}
//	}
//}
//unsigned _stdcall 整(void* arg) {
//	while (1) {
//		Gotxy(7, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[6][j]);
//		}
//	}
//}
//unsigned _stdcall 張(void* arg) {
//	while (1) {
//		Gotxy(8, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[7][j]);
//		}
//	}
//}
//unsigned _stdcall 独(void* arg) {
//	while (1) {
//		Gotxy(9, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[8][j]);
//		}
//	}
//}
//unsigned _stdcall 姥(void* arg) {
//	while (1) {
//		Gotxy(10, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[9][j]);
//		}
//	}
//}
//unsigned _stdcall 淑(void* arg) {
//	while (1) {
//		Gotxy(11, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[10][j]);
//		}
//	}
//}
//unsigned _stdcall 淑析(void* arg) {
//	while (1) {
//		Gotxy(12, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[11][j]);
//		}
//	}
//}
//unsigned _stdcall 淑戚(void* arg) {
//	while (1) {
//		Gotxy(13, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[12][j]);
//		}
//	}
//}
//unsigned _stdcall 淑誌(void* arg) {
//	while (1) {
//		Gotxy(14, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[13][j]);
//		}
//	}
//}
//unsigned _stdcall 淑紫(void* arg) {
//	while (1) {
//		Gotxy(15, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[14][j]);
//		}
//	}
//}
//unsigned _stdcall 淑神(void* arg) {
//	while (1) {
//		Gotxy(16, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[15][j]);
//		}
//	}
//}
//unsigned _stdcall 淑整(void* arg) {
//	while (1) {
//		Gotxy(17, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[16][j]);
//		}
//	}
//}
//unsigned _stdcall 淑張(void* arg) {
//	while (1) {
//		Gotxy(18, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[17][j]);
//		}
//	}
//}
//unsigned _stdcall 淑独(void* arg) {
//	while (1) {
//		Gotxy(19, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[18][j]);
//		}
//	}
//}
//unsigned _stdcall 淑姥(void* arg) {
//	while (1) {
//		Gotxy(20, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[19][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑(void* arg) {
//	while (1) {
//		Gotxy(21, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[20][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑析(void* arg) {
//	while (1) {
//		Gotxy(22, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[21][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑戚(void* arg) {
//	while (1) {
//		Gotxy(23, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[22][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑誌(void* arg) {
//	while (1) {
//		Gotxy(24, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[23][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑紫(void* arg) {
//	while (1) {
//		Gotxy(25, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[24][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑神(void* arg) {
//	while (1) {
//		Gotxy(26, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[25][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑整(void* arg) {
//	while (1) {
//		Gotxy(27, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[26][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑張(void* arg) {
//	while (1) {
//		Gotxy(28, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[27][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑独(void* arg) {
//	while (1) {
//		Gotxy(29, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[28][j]);
//		}
//	}
//}
//unsigned _stdcall 戚淑姥(void* arg) {
//	while (1) {
//		Gotxy(30, 1);
//		for (int j = 0; j < 174; j++) {
//			printf("%c", a[29][j]);
//		}
//	}
//}