//비행기 총게임

//시간을 주고 그중에 할시에 이동,공격 0

//반복문 사용 중 입력할수 있는지 확인 0

//스레드 한 줄 한줄 생성 (마지막 작업)속도 업 작업 0

//업 다운 한꼐 생성 0

//총알 이동 0

//총과 장에물 충돌 값 0

//비행키 이동 제한 버그 해제 0

//난위도 조절 총과 장물이동 나누기0

//충동 오류 잡기 C

//프로젝트 실행 만들기0

//보스전? -> //클리어 만들기

//2가지 모드 무한모드 보스모드

//게임 종료 화면 배드 만들기

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

unsigned _stdcall Thread_A(void* arg);

void Gotxy(int x, int y);

unsigned _stdcall 영(void* arg);

unsigned _stdcall move_장애물(void* arg);

void key_sel(void);

int main(void) {

	int key;
	int on = 0;
	int dow = 0;
	int hekp = 0;

	//////////////////////////////////////경개선///////////////////////////////////////////
	int main_moved;
	main_moved = 0;
re_move:
	system("cls");
	printf("\n\n\t1.게임 설명\n\n\t2.게임시작\n\n\t3.강제종료\n\n\t이동할 장소의 번호를 입력하세요 : ");
	scanf("%d", &main_moved);
	switch (main_moved)
	{
	case 1:key_sel(); break;
	case 2:	break;
	case 3:exit(0);	break;
	default:
		printf("다시 입력해 주세요.");
		Sleep(2000);
		goto re_move;
	}
	/////////////////////////////////////////////////////////////////////////////////////

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

	_beginthreadex(NULL, 0, 영, 0, 0, NULL);

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
			else if (key == 32) {
				Sleep(100);
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
unsigned _stdcall Thread_A(void* arg) {
	int wkd = rand() % 30;
	int temp = 0;
	int count = 0;
	while (1) {
		if (sum <= 15) {
			Sleep(1000);
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
		else if (sum > 250 && sum <= 300) {
			Sleep(100);
		}
		
		//Sleep(1000-sum);

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
		for (int i = 0; i < 30; i++) {//점수
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 62 && a[i][j - 1] == 64 || a[i][j] == 62 && a[i][j-2] == 64) {
					a[i][j] = 32;
					a[i][j - 1] = 32;
					a[i][j - 2] = 32;
					sum++;
				}
				if (a[i][j] == 62&& a[i][j+1]==64|| a[i][j] == 62 && a[i][j + 2] == 64) {
					a[i][j] = 32;
					a[i][j+1] = 32;
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
	int z[10] = {"GAME OVER"};
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
		
	}
}
void key_sel(void) {
	int a;
	system("cls");
	printf(" 게임 설명\n\n\n");
	printf("\t\t0000000000\n");
	printf("\t\t   000\n");
	printf("\t0	 00000000\n");
	printf("\t0000000000000000000\n");
	printf("\t0	 00000000ㅡ\n\n");
	printf("여러분은 핼기 입니다. 장애물에 부딪히지 않게 총과 무빙으로 살아 남으세요.\n\n\n");
	printf("↑: 위로 한칸 올라갑니다.\t");
	printf("↓: 위로 한칸 올라갑니다.\t");
	printf("스페이스바: 공격을 합니다.\n\n");
	printf("\t\t\t@ : 장애물입니다. \t\t\t");
	printf("> : 공격시 나가는 총알 입니다.\n\n");
	printf("\t\t\t0 : 헬기를 구성하는 구조입니다. 장애물에 부딪히지 않게 저지하세요\n\n"); 
	printf("\t\t★해당 게임은 전체화면만 지원합니다. 게임 시작전 전체화면은 해주시길 바랍니다.★\n\n");
	printf("\t\t\t<전체화면을 하지 않을시 그래픽 문제가 일어날 수 있습니다>\n\n\n");
	printf("아무키나 누른 후 엔터를 누르면 게임이 시작됩니다. : ");
	scanf("%d", &a);
}