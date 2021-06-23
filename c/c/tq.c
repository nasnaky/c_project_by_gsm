//비행기 총게임

//시간을 주고 그중에 할시에 이동,공격 0

//반복문 사용 중 입력할수 있는지 확인 0

//스레드 한 줄 한줄 생성 (마지막 작업)속도 업 작업

//업 다운 한꼐 생성 0

//총알 이동 0

//총과 장에물 충돌 값 0

//비행키 이동 제한 버그 해제 0

//난위도 조절

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
//printf("\t0	  00000000ㅡ\n");


#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include <process.h>
#include<stdlib.h>
#include<conio.h>

#define RIGHT 77  
#define UP 72  
#define DOWN 80 

int a[30][175];
int sum = 0;

unsigned _stdcall Thread_A(void* arg);

void Gotxy(int x, int y);

unsigned _stdcall 영(void* arg);



int main(void) {

	int key;
	int on = 0;
	int dow = 0;
	int hekp = 0;


	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 175; j++) {
			a[i][j] = 32;
		}
	}

	// 이후 위아래에 사용
	for (int a1 = 0; a1 < 14; a1++) {
		a[10][17 - a1] = 48;
	}// 이후 위아래에 사용
	for (int a1 = 0; a1 < 3; a1++) {
		a[11][12 - a1] = 48;
	}
	a[12][0] = 48;
	for (int a1 = 0; a1 < 6; a1++) {
		a[12][13 - a1] = 48;
	}
	for (int a1 = 0; a1 < 17; a1++) {
		a[13][0 + a1] = 48;
	}
	a[14][0] = 48;
	for (int a1 = 0; a1 < 6; a1++) {
		a[14][13 - a1] = 48;
	}
	a[14][14] = 45;
	a[14][15] = 45;



	_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);//출력 프린트 

	_beginthreadex(NULL, 0,영, 0, 0, NULL);

	while (1) {
		key = 0;//초기화

		if (kbhit()) { //몰라
			key = getch(); //키이력
			if (key == 224) {//키 입력
				do { key = getch(); } while (key == 224);//키 입력시 입려
				if (key == UP) {//위로
					on++;
					if (a[0][10]==48) {//이동제한
						on--;
						continue;
					}
					for (int i = 0; i < 30; i++) {//이동 삭제
						for (int j = 0; j < 175; j++) {
							if (a[i][j] == 48 || a[i][j] == 45) {
								a[i][j] = 32;
							}
						}
					}
					for (int a1 = 0; a1 < 14; a1++) {//위로 올라감
						a[10 - on + dow][17 - a1] = 48;
					}
					for (int a1 = 0; a1 < 3; a1++) {
						a[11 - on + dow][12 - a1] = 48;
					}
					a[12 - on + dow][0] = 48;
					for (int a1 = 0; a1 < 6; a1++) {
						a[12 - on + dow][13 - a1] = 48;
					}
					for (int a1 = 0; a1 < 17; a1++) {
						a[13 - on + dow][0 + a1] = 48;
					}
					a[14 - on + dow][0] = 48;
					for (int a1 = 0; a1 < 6; a1++) {
						a[14 - on + dow][13 - a1] = 48;
					}
					a[14 - on + dow][14] = 45;
					a[14 - on + dow][15] = 45;
				}
				if (key == DOWN) {//아래로
					dow++;
					if (a[29][10] == 48){//이동 제한 문제 
						dow--;
						continue;
					}
					for (int i = 0; i < 30; i++) {//이동 삭제
						for (int j = 0; j < 175; j++) {
							if (a[i][j] == 48 || a[i][j] == 45) {
								a[i][j] = 32;
							}
						}
					}
					for (int a1 = 0; a1 < 14; a1++) {//이동 들어갑
						a[10 - on + dow][17 - a1] = 48;
					}
					for (int a1 = 0; a1 < 3; a1++) {
						a[11 - on + dow][12 - a1] = 48;
					}
					a[12 - on + dow][0] = 48;
					for (int a1 = 0; a1 < 6; a1++) {
						a[12 - on + dow][13 - a1] = 48;
					}
					for (int a1 = 0; a1 < 17; a1++) {
						a[13 - on + dow][0 + a1] = 48;
					}
					a[14 - on + dow][0] = 48;
					for (int a1 = 0; a1 < 6; a1++) {
						a[14 - on + dow][13 - a1] = 48;
					}
					a[14 - on + dow][14] = 45;
					a[14 - on + dow][15] = 45;
				}
				if (key == RIGHT) {//쏘기
					hekp = 0;
					for (int i = 0; i < 30; i++) {
						for (int j = 0; j < 175; j++) {
							if (a[i][j] == 45) {
								hekp++;
								if (hekp == 2) {
									a[i][j + 3] = 62;
								}
							}
						}
					}
				}
			}
			
		}

	}
}

unsigned _stdcall Thread_A(void* arg) {
	int wkd = rand() % 30;
	int temp = 0;
	int count = 0;
	while (1) {
		Sleep(1000);
	re:
		wkd = rand() % 30;//장애물 랜덤
		if (wkd <= 4) {//장애물 위치 재함
			goto re;
		}
		a[wkd][174] = 64;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 64) {//장애물 이동
					temp = a[i][j];
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = temp;
					
				}
			}
		}
		for (int i = 0; i < 30; i++) {//총알 이동
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 62) {
					count++;
					if (count == 2) {
						count = 0;
						continue;
					}
					temp = a[i][j];
					a[i][j] = a[i][j + 1];
					a[i][j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < 30; i++) {//점수
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 62&& a[i][j+1]==64|| a[i][j] == 62 && a[i][j + 2] == 64) {
					a[i][j] = 32;
					a[i][j+1] = 32;
					a[i][j + 1] = 32;
					sum++;
				}
			}
		}
	}
}
void Gotxy(int x, int y)//원하는 위치에 출력하는 합수
{
	COORD Pos = { y - 1,x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
unsigned _stdcall 영(void* arg) {
	while (1) {
		Gotxy(1, 1);
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 174; j++) {
				printf("%c", a[0+i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < 30; i++) {//종료뭄
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 48 && a[i][j + 1] == 64 || a[i][j] == 45 && a[i][j + 1] == 64) {
					for (int a12 = 0; a12 <= 5; a12++) {
						system("cls");
						printf("GAME OVER\n점수 : %d\n", sum);
						printf("%d초 뒤 종료 됩니다.", 5 - a12);
						Sleep(1000);
					}
					exit(0);
				}
			}
		}
	}
}
