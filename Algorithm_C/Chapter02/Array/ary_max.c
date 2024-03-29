#include<stdio.h>
#include<stdlib.h>

int maxof(int[], int);

void main() {
	int i;
	int* height; // 배열의 첫 번째 요소의 포인터
	int number;
	printf("사람 수: ");
	scanf("%d", &number);
	height = calloc(number, sizeof(int)); // 요소 개수가 number인 키 배열 생성
	printf("%d 사람의 키를 입력하세요.\n", number);
	for (i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf("%d", &height[i]);
	}
	printf("최댓값은 %d입니다.\n", maxof(height, number));
	free(height);

	return 0;
}

/* 요소 개수가 n인 배열 a의 요소의 최댓값 구하기 */
int maxof(const int a[], int n) {
	int i;
	int max = a[0]; // 최댓값
	for (i = 1; i < n; i++)
		if (a[i] > max) max = a[i];
	return max;
}