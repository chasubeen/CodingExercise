#include<stdio.h>

/* 1, 2, ..., n�� �� ���ϱ� */

void main() {
	int i, n;
	int sum;
	puts("1���� n������ ���� ���մϴ�.");
	printf("n�� ��: ");
	scanf("%d", &n);
	sum = 0;
	i = 1;
	while (i <= n) {
		sum += i;
		i++;
	}
	printf("1���� %d������ ���� %d�Դϴ�.\n",n,sum);

	return 0;
}

