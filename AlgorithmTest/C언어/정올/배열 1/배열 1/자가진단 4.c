/*
문제
100 개의 정수를 저장할 수 있는 배열을 선언하고 정수를 차례로 입력받다가 0 이 입력되면 0 을 제외하고 
그 때까지 입력된 정수를 가장 나중에 입력된 정수부터 차례대로(역순으로) 출력하는 프로그램을 작성하시오.
입력 예
3 5 10 55 0
출력 예
55 10 5 3
*/

#include<stdio.h>

void main() {
	int i;
	int a[100];
	// 100개의 정수를 입력받는 과정
	for (i = 0; i < 100; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			break;
		}
	}
	// 역순으로 출력
	i--; // 0을 제외하는 과정
	for(;i>=0;i--){
		printf("%d ", a[i]);
	}
	printf("\n");
}