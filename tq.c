//����� �Ѱ���

//�ð��� �ְ� ���߿� �ҽÿ� �̵�,���� 0

//�ݺ��� ��� �� �Է��Ҽ� �ִ��� Ȯ�� 0

//������ �� �� ���� ���� (������ �۾�)�ӵ� �� �۾� 0

//�� �ٿ� �Ѳ� ���� 0

//�Ѿ� �̵� 0

//�Ѱ� �忡�� �浹 �� 0

//����Ű �̵� ���� ���� ���� 0

//������ ���� �Ѱ� �幰�̵� ������0

//�浿 ���� ��� 0

//������Ʈ ���� �����0

//������? -> //Ŭ���� ����� X 

//2���� ��� ���Ѹ�� ������� X

//���� ���� ȭ�� ��� ����� C

//�� ���� �ذ� 0

//���� �پ缺 3�� 0

//�浹 ���Ʒ� ���� �ذ� C

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
//printf("\t0	 00000000��\n");


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

unsigned _stdcall ��(void* arg);

unsigned _stdcall move_��ֹ�(void* arg);

void key_sel(void);

unsigned _stdcall ��2(void* arg);

unsigned _stdcall ��1(void* arg);

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
	// ���� ���Ʒ��� ���
	for (int a1 = 0; a1 < 14; a1++) {
		a[10][17 - a1] = 48;
	}// ���� ���Ʒ��� ���
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

	_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);//��� ����Ʈ 

	_beginthreadex(NULL, 0, ��, 0, 0, NULL);

	_beginthreadex(NULL, 0, ��1, 0, 0, NULL);

	_beginthreadex(NULL, 0, ��2, 0, 0, NULL);

	_beginthreadex(NULL, 0, move_��ֹ�, 0, 0, NULL);

	while (1) {
		key = 0;//�ʱ�ȭ

		if (kbhit()) { //����
			key = getch(); //Ű�̷�
			if (key == 224) {//Ű �Է�
				do { key = getch(); } while (key == 224);//Ű �Է½� �Է�
				if (key == UP) {//����
					on++;
					if (a[0][10] == 48) {//�̵�����
						on--;
						continue;
					}
					for (int a1 = 0; a1 < 14; a1++) {
						if (a[10 - on + dow - 1][17 - a1] == 63|| a[10 - on + dow - 1][17 - a1] == 64|| a[10 - on + dow - 1][17 - a1] == 92) {
									system("cls");
									Gotxy(20, 90);
									printf("GAME OVER");
									Gotxy(30, 175);
									printf("���� : %d", sum);
									Gotxy(40, 1);
								exit(0);
						}
					}
					for (int i = 0; i < 30; i++) {//�̵� ����
						for (int j = 0; j < 175; j++) {
							if (a[i][j] == 48 || a[i][j] == 45) {
								a[i][j] = 32;
							}
						}
					}
					for (int a1 = 0; a1 < 14; a1++) {//���� �ö�
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
				if (key == DOWN) {//�Ʒ���
					dow++;
					if (a[29][10] == 48) {//�̵� ���� ���� 
						dow--;
						continue;
					}
					for (int a1 = 0; a1 < 14; a1++) {
						if (a[14 - on + dow + 1][17 - a1] == 63 || a[10 - on + dow - 1][17 - a1] == 64 || a[10 - on + dow - 1][17 - a1] == 92) {
							system("cls");
							Gotxy(20, 90);
							printf("GAME OVER");
							Gotxy(30, 175);
							printf("���� : %d", sum);
							Gotxy(40, 1);
							exit(0);
						}
					}
					for (int i = 0; i < 30; i++) {//�̵� ����
						for (int j = 0; j < 175; j++) {
							if (a[i][j] == 48 || a[i][j] == 45) {
								a[i][j] = 32;
							}
						}
					}
					for (int a1 = 0; a1 < 14; a1++) {//�̵� ��
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
				printf("������ %d�Դϴ�.", sum);
				exit(0);
			}
			else if (key == 122) {//����
				gun = 42;
			}
			else if (key == 120) {//����
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
				if (a[i][j] == 64) {//��ֹ� �̵�
					temp = a[i][j];
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = temp;
					
				}
			}
		}
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 92) {//��ֹ� �̵�
					temp = a[i][j];
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = temp;

				}
			}
		}
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 63) {//��ֹ� �̵�
					temp = a[i][j];
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = temp;

				}
			}
		}
	}
}
void Gotxy(int x, int y)//���ϴ� ��ġ�� ����ϴ� �ռ�
{
	COORD Pos = { y - 1,x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
unsigned _stdcall ��2(void* arg) {
	while (1) {
		for (int i = 0; i < 30; i++) {//����
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
		}//�⺻
		for (int i = 0; i < 30; i++) {//���� 61
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
		for (int i = 0; i < 30; i++) {//���� 42
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
unsigned _stdcall ��(void* arg) {
	int z[10] = {"GAME OVER"};
	while (1) {
		Gotxy(1, 1);
		printf("���� : %d", sum);
		Gotxy(1, 100);
		printf("����ź : %d\t����ź : %d\n",bob, rhks);
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 174; j++) {
				printf("%c", a[0+i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < 30; i++) {//���ṳ
			for (int j = 0; j < 175; j++) {

				if (a[i][j] == 48 && a[i][j + 1] == 64 || a[i][j] == 45 && a[i][j + 1] == 64) {
					for (int a12 = 0; a12 <= 5; a12++) {
						system("cls");
						Gotxy(20, 90);
						printf("GAME OVER");
						Gotxy(30, 175);
						printf("���� : %d", sum);
						Gotxy(40, 1);
						printf("%d�� �� ���� �˴ϴ�.", 5 - a12);
						Sleep(1000);
					}
					exit(0);
				}
			}
		}
		
	}
}
unsigned _stdcall ��1(void* arg) {
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
		wkd = rand() % 30;//��ֹ� ����
		if (wkd <= 4) {//��ֹ� ��ġ ����
			goto re;
		}
		aa = rand() % 30;
		if (aa == 1) {//����
			a[wkd][174] = 92;
		}
		else if (aa >= 2&&aa <= 5) {//����
			a[wkd][174] = 63;
		}
		else {//�⺻
			a[wkd][174] = 64;
		}
	}
}
unsigned _stdcall move_��ֹ�(void* arg) {
	int temp = 0;
	int count = 0;
	while (1) {
		Sleep(50);
		for (int i = 0; i < 30; i++) {//�Ѿ� �̵�
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
		for (int i = 0; i < 30; i++) {//�Ѿ� �̵�
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
		for (int i = 0; i < 30; i++) {//�Ѿ� �̵�
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
	printf(" ���� ����\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t0000000000\n");
	printf("\t\t\t\t\t\t\t\t\t\t   000\n");
	printf("\t\t\t\t\t\t\t\t\t0	 00000000\n");
	printf("\t\t\t\t\t\t\t\t\t0000000000000000000\n");
	printf("\t\t\t\t\t\t\t\t\t0	 00000000��\n\n");
	printf("\t\t\t\t\t\t�������� �۱� �Դϴ�. ��ֹ��� �ε����� �ʰ� �Ѱ� �������� ��� ��������.\n\n\n");
	printf("��: ���� ��ĭ �ö󰩴ϴ�.\t\t\t");
	printf("��: ���� ��ĭ �ö󰩴ϴ�.\t\t\t");
	printf("�����̽���: ������ �մϴ�.\t\t\t");
	printf("\t\t\t@ : ��ֹ��Դϴ�. \t\t\n\n");
	printf("> : ���ݽ� ������ �Ѿ� �Դϴ�.\n\n");
	printf("\t\t\t0 : ��⸦ �����ϴ� �����Դϴ�. ��ֹ��� �ε����� �ʰ� �����ϼ���\n\n"); 
	printf("\t\t���ش� ������ ��üȭ�鸸 �����մϴ�. ���� ������ ��üȭ���� ���ֽñ� �ٶ��ϴ�.��\n\n");
	printf("\t\t\t<��üȭ���� ���� ������ �׷��� ������ �Ͼ �� �ֽ��ϴ�>\n\n\n");
	printf("�ƹ�Ű�� ���� �� ���͸� ������ ������ ���۵˴ϴ�. : ");
	scanf("%d", &a);
}