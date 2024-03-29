/* 버블 정렬 */
#include<stdio.h>
#include<stdlib.h>
#define swap(type,x,y) do{type t = x;x = y;y = t;}while(0)

// 버블 정렬
void bubble(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
	}
}

void main() {
	int i, nx;
	int* x; // 배열의 첫 번째 요소에 대한 포인터 

	puts("버블 정렬");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); // 요소의 개수가 nx인 int형 배열 생성

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx); // 배열 x를 버블 정렬

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}