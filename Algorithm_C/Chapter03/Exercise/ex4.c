// ���� �˻�
#include<stdio.h>
#include<stdlib.h>

// ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�
int bin_search(const int a[], int n, int key) {
	int i;
	int pl = 0; // �˻� ���� �� ���� �ε���
	int pr = n - 1; // �˻� ���� �� ���� �ε���
	int pc; // �˻� ���� �Ѱ���� �ε���

	printf("   |"); // ���� ó���� |
	for (i = 0; i < n; i++) printf("%4d", i); // �� ���� �� ���
	printf("\n---+"); // ���м� ���� ó��(+����)
	for (i = 0; i < n; i++) printf("----"); // ���м� ������
	printf("-\n"); // ����

	do {
		pc = (pl + pr) / 2;

		/* ���� ��� */
		printf("   |");
		for (i = 0; i < 4 * pl; i++) printf(" "); // pl ��ġ���� �̵�(���� ǥ��)
		printf(" <-"); // �� �� ���
		for (i = 0; i < 4 * (pc - pl); i++) printf(" "); // pc ��ġ���� �̵� 
		printf("+"); // Ž�� �߾� ���
		for (i = 0; i < 4 * (pr - pc) - 2; i++) printf(" ");
		printf("->\n"); // �� ������ ���
		printf("%3d|", pc); // �� ���ʿ� ���� �˻����� ����� �ε��� ���
		for (i = 0; i < n; i++)
			printf("%4d", a[i]);
		putchar('\n');

		if (a[pc] == key) // �˻� ����
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while (pl <= pr);
	return -1;
}

void main() {
	int i, nx, ky, idx;
	int* x; // �迭�� ù ���� ��ҿ� ���� ������
	puts("���� �˻�");
	printf("��� ����: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); // ����� ������ nx�� int�� �迭 ����
	printf("������������ �Է��ϼ���.\n");
	printf("x[0]: ");
	scanf("%d", &x[0]);
	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("�˻� ��: ");
	scanf("%d", &ky);
	idx = bin_search(x, nx, ky);
	if (idx == -1)
		puts("�˻��� �����Ͽ����ϴ�.");
	else
		printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, idx);
	free(x);
}