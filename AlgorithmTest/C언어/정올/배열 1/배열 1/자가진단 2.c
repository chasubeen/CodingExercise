/*
문제
정수 10 개를 저장할 수 있는 배열을 만들어서 1 부터 10 까지를 대입하고 
차례대로 출력하는 프로그램을 작성하시오.
출력 예
1 2 3 4 5 6 7 8 9 10
*/

#include<stdio.h>
void main() {
	int i;
	int arr[10];
	for (i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}