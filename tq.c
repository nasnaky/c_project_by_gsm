//비행기 총게임

//시간을 주고 그중에 할시에 이동,공격 0

//반복문 사용 중 입력할수 있는지 확인 0

//스레드 한 줄 한줄 생성 (마지막 작업)속도 업 작업 0

//업 다운 한꼐 생성 0

//총알 이동 0

//총과 장에물 충돌 값 0

//비행키 이동 제한 버그 해제 0

//난위도 조절 총과 장물이동 나누기0

//충동 오류 잡기 0

//프로젝트 실행 만들기0

//보스전? -> //클리어 만들기 X 

//2가지 모드 무한모드 보스모드 X

//게임 종료 화면 배드 만들기 C

//총 버그 해결 0

//무기 다양성 3개 0

//충돌 위아래 버그 해결 C

//		0000000000
//	  	   000
//0		 00000000
//000000000000000000
//0	     00000000--
//		
//printf("\t\t0000000000\n");
//printf("\t\t   000\n");
//printf("\t0	 00000000\n");
//printf("\t0000000000000000000\n");
//printf("\t0	 00000000ㅡ\n");


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
int sum = 200;
int bob = 0;
int rhks = 0;

unsigned _stdcall Thread_A(void* arg);

void Gotxy(int x, int y);

unsigned _stdcall 영(void* arg);

unsigned _stdcall move_장애물(void* arg);

void key_sel(void);

unsigned _stdcall 영2(void* arg);

unsigned _stdcall 영1(void* arg);

int main(void) {
	srand(time(NULL));
	int key;
	int on = 0;
	int dow = 0;
	int hekp = 0;
	int gun =62;

	key_sel();

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

	system("cls");

	_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);//출력 프린트 

	_beginthreadex(NULL, 0, 영, 0, 0, NULL);

	_beginthreadex(NULL, 0, 영1, 0, 0, NULL);

	_beginthreadex(NULL, 0, 영2, 0, 0, NULL);

	_beginthreadex(NULL, 0, move_장애물, 0, 0, NULL);

	while (1) {
		key = 0;//초기화

		if (kbhit()) { //몰라
			key = getch(); //키이력
			if (key == 224) {//키 입력
				do { key = getch(); } while (key == 224);//키 입력시 입려
				if (key == UP) {//위로
					on++;
					if (a[0][10] == 48) {//이동제한
						on--;
						continue;
					}
					for (int a1 = 0; a1 < 14; a1++) {
						if (a[10 - on + dow - 1][17 - a1] == 63|| a[10 - on + dow - 1][17 - a1] == 64|| a[10 - on + dow - 1][17 - a1] == 92) {
									system("cls");
									Gotxy(20, 90);
									printf("GAME OVER");
									Gotxy(30, 175);
									printf("점수 : %d", sum);
									Gotxy(40, 1);
								exit(0);
						}
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
					if (a[29][10] == 48) {//이동 제한 문제 
						dow--;
						continue;
					}
					for (int a1 = 0; a1 < 14; a1++) {
						if (a[14 - on + dow + 1][17 - a1] == 63 || a[10 - on + dow - 1][17 - a1] == 64 || a[10 - on + dow - 1][17 - a1] == 92) {
							system("cls");
							Gotxy(20, 90);
							printf("GAME OVER");
							Gotxy(30, 175);
							printf("점수 : %d", sum);
							Gotxy(40, 1);
							exit(0);
						}
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
			}
			else if (key == 27) {
				system("cls");
				printf("점수는 %d입니다.", sum);
				exit(0);
			}
			else if (key == 122) {//폭발
				gun = 42;
			}
			else if (key == 120) {//관통
				gun = 61;
			}
			else if (gun == 42) {
				if (bob == 0) {
					gun = 62;
				}
				else if (bob > 0) {
					bob -= 0.5;
				}
			}
			else if (gun == 61) {
				if (rhks == 0) {
					gun = 62;
				}
				else if (rhks > 0) {
					rhks -= 0.5;
				}
			}
			if (key == 32) {
				Sleep(100);
				hekp = 0;
				for (int i = 0; i < 30; i++) {
					for (int j = 0; j < 175; j++) {
						if (a[i][j] == 45) {
							hekp++;
							if (hekp == 2) {
								a[i][j + 3] = gun;
							}
						}
					}
				}
			}
		}
	}
}
unsigned _stdcall Thread_A(void* arg) {

	int temp = 0;
	int count = 0;
	while (1) {
		if (sum <= 15) {
			Sleep(700);
		}
		else if (sum > 15 &&sum <= 50) {
			Sleep(500);
		}
		else if (sum > 51 && sum <= 100) {
			Sleep(300);
		}
		else if (sum > 100 && sum <= 200) {
			Sleep(200);
		}
		else if (sum > 200 && sum <= 250) {
			Sleep(200);
		}
		else if (sum > 250) {
			Sleep(100);
		}


		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 64) {//장애물 이동
					temp = a[i][j];
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = temp;
					
				}
			}
		}
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 92) {//장애물 이동
					temp = a[i][j];
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = temp;

				}
			}
		}
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 63) {//장애물 이동
					temp = a[i][j];
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = temp;

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
unsigned _stdcall 영2(void* arg) {
	while (1) {
		for (int i = 0; i < 30; i++) {//점수
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 62 && a[i][j - 1] == 64 || a[i][j] == 62 && a[i][j - 2] == 64) {
					a[i][j] = 32;
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					sum++;
				}
				if (a[i][j] == 62 && a[i][j + 1] == 64 || a[i][j] == 62 && a[i][j + 2] == 64) {
					a[i][j] = 32;
					a[i][j + 1] = 32;
					a[i][j + 2] = 32;
					sum++;
				}
				if (a[i][j] == 62 && a[i][j + 3] == 64 || a[i][j] == 62 && a[i][j + 4] == 64) {
					a[i][j] = 32;
					a[i][j + 3] = 32;
					a[i][j + 4] = 32;
					sum++;
				}
				if (a[i][j] == 62 && a[i][j + 5] == 64 || a[i][j] == 62 && a[i][j + 6] == 64) {
					a[i][j] = 32;
					a[i][j + 5] = 32;
					a[i][j + 6] = 32;
					sum++;
				}
				if (a[i][j] == 62 && a[i][j + 7] == 64 || a[i][j] == 62 && a[i][j + 8] == 64) {
					a[i][j] = 32;
					a[i][j + 7] = 32;
					a[i][j + 8] = 32;
					sum++;
				}
				if (a[i][j] == 62 && a[i][j - 1] == 63 || a[i][j] == 62 && a[i][j - 2] == 63) {
					a[i][j] = 32;
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 62 && a[i][j + 1] == 63 || a[i][j] == 62 && a[i][j + 2] == 63) {
					a[i][j] = 32;
					a[i][j + 1] = 32;
					a[i][j + 2] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 62 && a[i][j + 3] == 63 || a[i][j] == 62 && a[i][j + 4] == 63) {
					a[i][j] = 32;
					a[i][j + 3] = 32;
					a[i][j + 4] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 62 && a[i][j + 5] == 63 || a[i][j] == 62 && a[i][j + 6] == 63) {
					a[i][j] = 32;
					a[i][j + 5] = 32;
					a[i][j + 6] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 62 && a[i][j + 7] == 63 || a[i][j] == 62 && a[i][j + 8] == 63) {
					a[i][j] = 32;
					a[i][j + 7] = 32;
					a[i][j + 8] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 62 && a[i][j - 1] == 92 || a[i][j] == 62 && a[i][j - 2] == 92) {
					a[i][j] = 32;
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 62 && a[i][j + 1] == 92 || a[i][j] == 62 && a[i][j + 2] == 92) {
					a[i][j] = 32;
					a[i][j + 1] = 32;
					a[i][j + 2] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 62 && a[i][j + 3] == 92 || a[i][j] == 62 && a[i][j + 4] == 92) {
					a[i][j] = 32;
					a[i][j + 3] = 32;
					a[i][j + 4] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 62 && a[i][j + 5] == 64 || a[i][j] == 62 && a[i][j + 6] == 64) {
					a[i][j] = 32;
					a[i][j + 5] = 32;
					a[i][j + 6] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 62 && a[i][j + 7] == 92 || a[i][j] == 62 && a[i][j + 8] == 92) {
					a[i][j] = 32;
					a[i][j + 7] = 32;
					a[i][j + 8] = 32;
					sum++;
					bob += 5;
				}
			}
		}//기본
		for (int i = 0; i < 30; i++) {//점수 61
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 61 && a[i][j - 1] == 64 || a[i][j] == 61 && a[i][j - 2] == 64) {
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					sum++;
				}
				if (a[i][j] == 61 && a[i][j + 1] == 64 || a[i][j] == 61 && a[i][j + 2] == 64) {
					a[i][j + 1] = 32;
					a[i][j + 2] = 32;
					sum++;
				}
				if (a[i][j] == 61 && a[i][j + 3] == 64 || a[i][j] == 61 && a[i][j + 4] == 64) {
					a[i][j + 3] = 32;
					a[i][j + 4] = 32;
					sum++;
				}
				if (a[i][j] == 61 && a[i][j + 5] == 64 || a[i][j] == 61 && a[i][j + 6] == 64) {
					a[i][j + 5] = 32;
					a[i][j + 6] = 32;
					sum++;
				}
				if (a[i][j] == 61 && a[i][j + 7] == 64 || a[i][j] == 61 && a[i][j + 8] == 64) {
					a[i][j + 7] = 32;
					a[i][j + 8] = 32;
					sum++;
				}
				if (a[i][j] == 61 && a[i][j - 1] == 63 || a[i][j] == 61 && a[i][j - 2] == 63) {
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 61 && a[i][j + 1] == 63 || a[i][j] == 61 && a[i][j + 2] == 63) {
					a[i][j + 1] = 32;
					a[i][j + 2] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 61 && a[i][j + 3] == 63 || a[i][j] == 61 && a[i][j + 4] == 63) {
					a[i][j + 3] = 32;
					a[i][j + 4] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 61 && a[i][j + 5] == 63 || a[i][j] == 61 && a[i][j + 6] == 63) {
					a[i][j + 5] = 32;
					a[i][j + 6] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 61 && a[i][j + 7] == 63 || a[i][j] == 61 && a[i][j + 8] == 63) {
					a[i][j + 7] = 32;
					a[i][j + 8] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 61 && a[i][j - 1] == 92 || a[i][j] == 61 && a[i][j - 2] == 92) {
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 61 && a[i][j + 1] == 92 || a[i][j] == 61 && a[i][j + 2] == 92) {
					a[i][j + 1] = 32;
					a[i][j + 2] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 61 && a[i][j + 3] == 92 || a[i][j] == 61 && a[i][j + 4] == 92) {
					a[i][j + 3] = 32;
					a[i][j + 4] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 61 && a[i][j + 5] == 64 || a[i][j] == 61 && a[i][j + 6] == 64) {
					a[i][j + 5] = 32;
					a[i][j + 6] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 61 && a[i][j + 7] == 92 || a[i][j] == 61 && a[i][j + 8] == 92) {
					a[i][j + 7] = 32;
					a[i][j + 8] = 32;
					sum++;
					bob += 5;
				}
			}
		}
		for (int i = 0; i < 30; i++) {//점수 42
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 42 && a[i][j - 1] == 64 || a[i][j] == 42 && a[i][j - 2] == 64) {
					a[i][j] = 32;
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					a[i - 1][j - 1] = 32;
					a[i + 1][j - 2] = 32;
					a[i + 1][j] = 32;
					a[i - 1][j] = 32;

					sum++;
				}
				if (a[i][j] == 42 && a[i][j + 1] == 64 || a[i][j] == 42 && a[i][j + 2] == 64) {
					a[i][j] = 32;
					a[i][j + 1] = 32;
					a[i][j + 2] = 32;
					a[i - 1][j + 1] = 32;
					a[i + 1][j + 2] = 32;
					a[i + 1][j + 1] = 32;
					a[i - 1][j + 2] = 32;
					sum++;
				}
				if (a[i][j] == 42 && a[i][j + 3] == 64 || a[i][j] == 42 && a[i][j + 4] == 64) {
					a[i][j] = 32;
					a[i][j + 3] = 32;
					a[i][j + 4] = 32;
					a[i - 1][j + 3] = 32;
					a[i + 1][j + 4] = 32;
					a[i + 1][j + 3] = 32;
					a[i - 1][j + 4] = 32;
					sum++;
				}
				if (a[i][j] == 42 && a[i][j + 5] == 64 || a[i][j] == 42 && a[i][j + 6] == 64) {
					a[i][j] = 32;
					a[i][j + 5] = 32;
					a[i][j + 6] = 32;
					a[i - 1][j + 5] = 32;
					a[i + 1][j + 6] = 32;
					a[i + 1][j + 5] = 32;
					a[i - 1][j + 6] = 32;
					sum++;
				}
				if (a[i][j] == 42 && a[i][j + 7] == 64 || a[i][j] == 42 && a[i][j + 8] == 64) {
					a[i][j] = 32;
					a[i][j + 7] = 32;
					a[i][j + 8] = 32;
					a[i - 1][j + 7] = 32;
					a[i + 1][j - +8] = 32;
					a[i + 1][j + 7] = 32;
					a[i - 1][j + 8] = 32;
					sum++;
				}
				if (a[i][j] == 42 && a[i][j - 1] == 63 || a[i][j] == 42 && a[i][j - 2] == 63) {
					a[i][j] = 32;
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					a[i - 1][j - 1] = 32;
					a[i + 1][j - 2] = 32;
					a[i + 1][j] = 32;
					a[i - 1][j] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 42 && a[i][j + 1] == 63 || a[i][j] == 42 && a[i][j + 2] == 63) {
					a[i][j] = 32;
					a[i][j + 1] = 32;
					a[i][j + 2] = 32;
					a[i - 1][j + 1] = 32;
					a[i + 1][j + 2] = 32;
					a[i + 1][j + 1] = 32;
					a[i - 1][j + 2] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 42 && a[i][j + 3] == 63 || a[i][j] == 42 && a[i][j + 4] == 63) {
					a[i][j] = 32;
					a[i][j + 3] = 32;
					a[i][j + 4] = 32;
					a[i - 1][j + 3] = 32;
					a[i + 1][j + 4] = 32;
					a[i + 1][j + 3] = 32;
					a[i - 1][j + 4] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 42 && a[i][j + 5] == 63 || a[i][j] == 42 && a[i][j + 6] == 63) {
					a[i][j] = 32;
					a[i][j + 5] = 32;
					a[i][j + 6] = 32;
					a[i - 1][j + 5] = 32;
					a[i + 1][j + 6] = 32;
					a[i + 1][j + 5] = 32;
					a[i - 1][j + 6] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 42 && a[i][j + 7] == 63 || a[i][j] == 42 && a[i][j + 8] == 63) {
					a[i][j] = 32;
					a[i][j + 7] = 32;
					a[i][j + 8] = 32;
					a[i - 1][j + 7] = 32;
					a[i + 1][j + 8] = 32;
					a[i + 1][j + 7] = 32;
					a[i - 1][j + 8] = 32;
					sum++;
					rhks += 5;
				}
				if (a[i][j] == 42 && a[i][j - 1] == 92 || a[i][j] == 42 && a[i][j - 2] == 92) {
					a[i][j] = 32;
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					a[i - 1][j - 1] = 32;
					a[i + 1][j - 2] = 32;
					a[i + 1][j] = 32;
					a[i - 1][j] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 42 && a[i][j + 1] == 92 || a[i][j] == 42 && a[i][j + 2] == 92) {
					a[i][j] = 32;
					a[i][j + 1] = 32;
					a[i][j + 2] = 32;
					a[i - 1][j + 1] = 32;
					a[i + 1][j + 2] = 32;
					a[i + 1][j + 1] = 32;
					a[i - 1][j + 2] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 42 && a[i][j + 3] == 92 || a[i][j] == 42 && a[i][j + 4] == 92) {
					a[i][j] = 32;
					a[i][j + 3] = 32;
					a[i][j + 4] = 32;
					a[i - 1][j + 3] = 32;
					a[i + 1][j + 4] = 32;
					a[i + 1][j + 3] = 32;
					a[i - 1][j + 4] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 42 && a[i][j + 5] == 64 || a[i][j] == 42 && a[i][j + 6] == 64) {
					a[i][j] = 32;
					a[i][j + 5] = 32;
					a[i][j + 6] = 32;
					a[i - 1][j + 5] = 32;
					a[i + 1][j + 6] = 32;
					a[i + 1][j + 5] = 32;
					a[i - 1][j + 6] = 32;
					sum++;
					bob += 5;
				}
				if (a[i][j] == 42 && a[i][j + 7] == 92 || a[i][j] == 42 && a[i][j + 8] == 92) {
					a[i][j] = 32;
					a[i][j + 7] = 32;
					a[i][j + 8] = 32;
					a[i - 1][j + 7] = 32;
					a[i + 1][j + 8] = 32;
					a[i + 1][j + 7] = 32;
					a[i - 1][j + 8] = 32;
					sum++;
					bob += 5;
				}
			}
		}
	}
}
unsigned _stdcall 영(void* arg) {
	int z[10] = {"GAME OVER"};
	while (1) {
		Gotxy(1, 1);
		printf("점수 : %d", sum);
		Gotxy(1, 100);
		printf("폭발탄 : %d\t관통탄 : %d\n",bob, rhks);
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
						Gotxy(20, 90);
						printf("GAME OVER");
						Gotxy(30, 175);
						printf("점수 : %d", sum);
						Gotxy(40, 1);
						printf("%d초 뒤 종료 됩니다.", 5 - a12);
						Sleep(1000);
					}
					exit(0);
				}
			}
		}
		
	}
}
unsigned _stdcall 영1(void* arg) {
	int aa;
	int wkd = rand() % 30;
	int ae;
	while (1) {
		ae = 1000 - sum;
		if (ae < 100) {
			ae = 100;
		}
		Sleep(ae);

	re:
		wkd = rand() % 30;//장애물 랜덤
		if (wkd <= 4) {//장애물 위치 재함
			goto re;
		}
		aa = rand() % 30;
		if (aa == 1) {//폭팔
			a[wkd][174] = 92;
		}
		else if (aa >= 2&&aa <= 5) {//관통
			a[wkd][174] = 63;
		}
		else {//기본
			a[wkd][174] = 64;
		}
	}
}
unsigned _stdcall move_장애물(void* arg) {
	int temp = 0;
	int count = 0;
	while (1) {
		Sleep(50);
		for (int i = 0; i < 30; i++) {//총알 이동
			for (int j = 0; j < 175; j++) {
				if (a[i][174] == 62) {
					a[i][174] = 32;
				}
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
		for (int i = 0; i < 30; i++) {//총알 이동
			for (int j = 0; j < 175; j++) {
				if (a[i][174] == 42) {
					a[i][174] = 32;
				}
				if (a[i][j] == 42) {
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
		for (int i = 0; i < 30; i++) {//총알 이동
			for (int j = 0; j < 175; j++) {
				if (a[i][174] == 61) {
					a[i][174] = 32;
				}
				if (a[i][j] == 61) {
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
		
	}

}
void key_sel(void) {
	int a;
	system("cls");
	printf(" 게임 설명\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t0000000000\n");
	printf("\t\t\t\t\t\t\t\t\t\t   000\n");
	printf("\t\t\t\t\t\t\t\t\t0	 00000000\n");
	printf("\t\t\t\t\t\t\t\t\t0000000000000000000\n");
	printf("\t\t\t\t\t\t\t\t\t0	 00000000ㅡ\n\n");
	printf("\t\t\t\t\t\t여러분은 핼기 입니다. 장애물에 부딪히지 않게 총과 무빙으로 살아 남으세요.\n\n\n");
	printf("↑: 위로 한칸 올라갑니다.\t\t\t");
	printf("↓: 위로 한칸 올라갑니다.\t\t\t");
	printf("스페이스바: 공격을 합니다.\t\t\t");
	printf("\t\t\t@ : 장애물입니다. \t\t\n\n");
	printf("> : 공격시 나가는 총알 입니다.\n\n");
	printf("\t\t\t0 : 헬기를 구성하는 구조입니다. 장애물에 부딪히지 않게 저지하세요\n\n"); 
	printf("\t\t★해당 게임은 전체화면만 지원합니다. 게임 시작전 전체화면은 해주시길 바랍니다.★\n\n");
	printf("\t\t\t<전체화면을 하지 않을시 그래픽 문제가 일어날 수 있습니다>\n\n\n");
	printf("아무키나 누른 후 엔터를 누르면 게임이 시작됩니다. : ");
	scanf("%d", &a);
}