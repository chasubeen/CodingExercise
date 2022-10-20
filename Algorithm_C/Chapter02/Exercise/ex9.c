#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void ary_copy(int a[], const int b[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = b[i];
	for (int i = 0; i < n / 2; i++)
		swap(char, a[i], a[n - i - 1]);
}

void main() {
	int i;
	int n;  // �迭 x�� y�� ��� ���� */

	printf("����� ���� : ");
	scanf("%d", &n);
	int* x = calloc(n, sizeof(int)); // ����� ������ n�� int�� �迭 x�� ���� 
	int* y = calloc(n, sizeof(int)); // ����� ������ n�� int�� �迭 y�� ���� 


	printf("%d���� ������ �Է��ϼ���.\n", n);
	for (i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	ary_copy(y, x, n); // �迭 x�� ��� ��Ҹ� �迭 y�� �����մϴ�.

	printf("�迭 x�� ��� ��Ҹ� �迭 y�� ���� �����߽��ϴ�.\n");
	for (i = 0; i < n; i++)
		printf("y[%d] = %d\n", i, y[i]);

	free(x); // �迭 x�� ���� 
	free(y); // �迭 y�� ���� 

}