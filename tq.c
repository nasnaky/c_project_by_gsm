//����� �Ѱ���

//�ð��� �ְ� ���߿� �ҽÿ� �̵�,���� 0

//�ݺ��� ��� �� �Է��Ҽ� �ִ��� Ȯ�� 0

//������ �� �� ���� ���� (������ �۾�)�ӵ� �� �۾� 0

//�� �ٿ� �Ѳ� ���� 0

//�Ѿ� �̵� 0

//�Ѱ� �忡�� �浹 �� 0

//����Ű �̵� ���� ���� ���� 0

//������ ���� �Ѱ� �幰�̵� ������0

//�浿 ���� ��� C

//������Ʈ ���� �����0

//������? -> //Ŭ���� �����

//2���� ��� ���Ѹ�� �������

//���� ���� ȭ�� ��� �����

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

unsigned _stdcall Thread_A(void* arg);

void Gotxy(int x, int y);

unsigned _stdcall ��(void* arg);

unsigned _stdcall move_��ֹ�(void* arg);

void key_sel(void);

int main(void) {

	int key;
	int on = 0;
	int dow = 0;
	int hekp = 0;

	//////////////////////////////////////�氳��///////////////////////////////////////////
	int main_moved;
	main_moved = 0;
re_move:
	system("cls");
	printf("\n\n\t1.���� ����\n\n\t2.���ӽ���\n\n\t3.��������\n\n\t�̵��� ����� ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &main_moved);
	switch (main_moved)
	{
	case 1:key_sel(); break;
	case 2:	break;
	case 3:exit(0);	break;
	default:
		printf("�ٽ� �Է��� �ּ���.");
		Sleep(2000);
		goto re_move;
	}
	/////////////////////////////////////////////////////////////////////////////////////

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

	_beginthreadex(NULL, 0, ��, 0, 0, NULL);

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
		for (int i = 0; i < 30; i++) {//����
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
void Gotxy(int x, int y)//���ϴ� ��ġ�� ����ϴ� �ռ�
{
	COORD Pos = { y - 1,x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
unsigned _stdcall ��(void* arg) {
	int z[10] = {"GAME OVER"};
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
		
	}
}
void key_sel(void) {
	int a;
	system("cls");
	printf(" ���� ����\n\n\n");
	printf("\t\t0000000000\n");
	printf("\t\t   000\n");
	printf("\t0	 00000000\n");
	printf("\t0000000000000000000\n");
	printf("\t0	 00000000��\n\n");
	printf("�������� �۱� �Դϴ�. ��ֹ��� �ε����� �ʰ� �Ѱ� �������� ��� ��������.\n\n\n");
	printf("��: ���� ��ĭ �ö󰩴ϴ�.\t");
	printf("��: ���� ��ĭ �ö󰩴ϴ�.\t");
	printf("�����̽���: ������ �մϴ�.\n\n");
	printf("\t\t\t@ : ��ֹ��Դϴ�. \t\t\t");
	printf("> : ���ݽ� ������ �Ѿ� �Դϴ�.\n\n");
	printf("\t\t\t0 : ��⸦ �����ϴ� �����Դϴ�. ��ֹ��� �ε����� �ʰ� �����ϼ���\n\n"); 
	printf("\t\t���ش� ������ ��üȭ�鸸 �����մϴ�. ���� ������ ��üȭ���� ���ֽñ� �ٶ��ϴ�.��\n\n");
	printf("\t\t\t<��üȭ���� ���� ������ �׷��� ������ �Ͼ �� �ֽ��ϴ�>\n\n\n");
	printf("�ƹ�Ű�� ���� �� ���͸� ������ ������ ���۵˴ϴ�. : ");
	scanf("%d", &a);
}