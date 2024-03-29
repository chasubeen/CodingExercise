/*--- 단순 선택 정렬 ---*/
#include<stdio.h>
#include<stdlib.h>
#define swap(type,x,y) do{type t = x;x = y;y = t;}while(0)

// 선택 정렬
void selection(int a[],int n){
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++)
			if(a[j] < a[min])
				min = j;
		swap(int, a[i], a[min]);
	}
}

void main() {
	int i, nx;
	int* x; // 배열의 첫 번째 요소에 대한 포인터 

	puts("선택 정렬");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); // 요소의 개수가 nx인 int형 배열 생성

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}

	selection(x, nx); // 배열 x를 버블 정렬

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);
}