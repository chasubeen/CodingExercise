/* �迭 ����� �ִ� ���ϱ� */
#include<stdio.h>
#include<stdlib.h>

int minof(const int a[], int n) {
	int i;
	int min = a[0];
	for (i = 1; i < n; i++)
		if (a[i] < min) min = a[i];
	return min;
}

void main() {
	int i;
	int* height; // �迭�� ù ��° ����� ������
	int number; // �ο� = �迭 height�� ����� ����
	printf("��� ��: ");
	scanf("%d", &number);
	height = calloc(number, sizeof(int)); // ��� ������ number�� Ű �迭 ����
	printf("%d ����� Ű�� �Է��ϼ���.\n", number);
	for (i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf("%d", &height[i]);
	}
	printf("�ּڰ��� %d�Դϴ�.\n", minof(height, number));
	free(height); // �迭�� �޸� ����
}