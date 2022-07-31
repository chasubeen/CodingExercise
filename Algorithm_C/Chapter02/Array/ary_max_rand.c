#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// �迭 ����� �ִ� ���ϱ�(��: ���� ����)

// ��� ������ n�� �迭 a�� ����� �ִ� ���ϱ�
int maxof(const int a[], int n) {
	int i;
	int max = a[0];
	for (i = 1; i < n; i++)
		if (a[i] > max) max = a[i];
	return max;
}

void main() {
	int i;
	int* height; // �迭�� ù ��° ��� ������
	int number; // ��� ��: �迭 height�� ��� ����
	printf("����� ��: ");
	scanf("%d", &number);
	height = calloc(number, sizeof(int)); // ��� ������ number�� �迭 ����
	srand(time(NULL)); // �ð����� ������ seed�� �ʱ�ȭ
	for (i = 0; i < number; i++) {
		height[i] = 100 + rand() % 90; // 100 ~ 189�� ���� ���� & ����
		printf("height[%d] = %d\n", i, height[i]);
	}
	printf("�ִ��� %d�Դϴ�.\n", maxof(height, number));
	free(height);

	return 0;
}