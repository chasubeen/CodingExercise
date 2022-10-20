#include <stdio.h>

/*--- type ���� x�� y�� ���� ��ȯ ---*/
#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

/*--- ���� x�� n ������ ��ȯ�ϰ� �迭 d�� �Ʒ��ڸ����� ���� ---*/
int card_conv(unsigned x, int n, char d[]){
	int i;
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // ���� ��ȯ ��(10���ʹ� A ~ )
	int digits = 0; // ��ȯ �� �ڸ���

	if (x == 0)										// 0�̸� 
		d[digits++] = dchar[0];						// ��ȯ �ڿ��� 0 

	else {											// 0�� �ƴ϶�� 
		while (x) { // x�� ���� �� ���� ������
			printf("%2d | %7d ... %c\n", n, x, dchar[x % n]);
			printf("   + ---------- \n");
			d[digits++] = dchar[x % n];				 // n���� ���� �������� ������ ����
			x /= n; // x ����
		}
		printf("%12d\n", x);
	}

	/* d[0] ~ d[digits -1]�� ���� �������� ���� */
	for (i = 0; i <digits / 2; i++)
		swap(char, d[i], d[digits - i - 1]);

	return digits;
}

void main(){
	int i;
	unsigned no;			// ��ȯ�ϴ� ���� 
	int cd;					// ��� 
	int dno;				// ��ȯ �� �ڸ��� 
	char cno[512];			// ��ȯ �� �� �ڸ��� ���ڸ� �־�δ� ���� �迭 
	int retry;				// �ٽ� �� ��? 

	puts("10 ������ ����� ��ȯ�մϴ�.");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		scanf("%u", &no);
		do {
			printf("���� ������ ��ȯ�մϱ�?(2 ~ 36) : ");
			scanf("%d", &cd);
		} while (cd < 2 || cd > 36); // �Է¹޴� ���� ���� ����

		dno = card_conv(no, cd, cno);		// no�� cd ������ ��ȯ

		printf("%d ������ ", cd);
		for (i = 0; i <dno; i++)			// ���ڸ����� ǥ��
			printf("%c", cno[i]);
		printf("�Դϴ�.\n");

		printf("�ٽ� �� �� �ұ��?(1 �� / 0 �ƴϿ�): ");
		scanf("%d", &retry);
	} while (retry == 1);
}