/*
문제
실수 5개를 원소로 하는 배열을 선언하고 포인터 변수를 이용하여 입력과 출력을 실행하는 프로그램을 작성하시오.
출력은 반올림하여 소수 첫째자리까지 출력하는 것으로 한다.
입력 예
10 25.3 1.05 0.78 100
출력 예
10.0 25.3 1.1 0.8 100.0
*/

#include<stdio.h>

void main() {
	double a[5];
	double *ptr = a;
	
	for (int i = 0; i < 5; i++) {
		scanf("%lf", &ptr[i]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%.1lf ", ptr[i]);
	}
	return 0;
	printf("\n");
}