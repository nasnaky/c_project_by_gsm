//����� �Ѱ���

//�ð��� �ְ� ���߿� �ҽÿ� �̵�,���� 0

//�ݺ��� ��� �� �Է��Ҽ� �ִ��� Ȯ�� 0

//������ �� �� ���� ���� (������ �۾�)�ӵ� �� �۾�

//�� �ٿ� �Ѳ� ���� 0

//�Ѿ� �̵� 0

//�Ѱ� �忡�� �浹 �� 0

//����Ű �̵� ���� ���� ���� 0

//������ ����

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
//printf("\t0	  00000000��\n");


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

unsigned _stdcall ��(void* arg);



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



	_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);//��� ����Ʈ 

	_beginthreadex(NULL, 0,��, 0, 0, NULL);

	while (1) {
		key = 0;//�ʱ�ȭ

		if (kbhit()) { //����
			key = getch(); //Ű�̷�
			if (key == 224) {//Ű �Է�
				do { key = getch(); } while (key == 224);//Ű �Է½� �Է�
				if (key == UP) {//����
					on++;
					if (a[0][10]==48) {//�̵�����
						on--;
						continue;
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
					if (a[29][10] == 48){//�̵� ���� ���� 
						dow--;
						continue;
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
				if (key == RIGHT) {//���
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
		wkd = rand() % 30;//��ֹ� ����
		if (wkd <= 4) {//��ֹ� ��ġ ����
			goto re;
		}
		a[wkd][174] = 64;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 175; j++) {
				if (a[i][j] == 64) {//��ֹ� �̵�
					temp = a[i][j];
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = temp;
					
				}
			}
		}
		for (int i = 0; i < 30; i++) {//�Ѿ� �̵�
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
		for (int i = 0; i < 30; i++) {//����
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
void Gotxy(int x, int y)//���ϴ� ��ġ�� ����ϴ� �ռ�
{
	COORD Pos = { y - 1,x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
unsigned _stdcall ��(void* arg) {
	while (1) {
		Gotxy(1, 1);
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
						printf("GAME OVER\n���� : %d\n", sum);
						printf("%d�� �� ���� �˴ϴ�.", 5 - a12);
						Sleep(1000);
					}
					exit(0);
				}
			}
		}
	}
}
