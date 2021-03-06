/*
문제
배열을 만들어서 아래와 같이 저장한 후 출력하는 프로그램을 작성하시오. 
규칙은 첫 번째 행은 모두 1로 초기화 하고 다음 행부터는 바로 위의 값과 바로 왼쪽의 값을 더한 것이다.
출력 예
1 1 1 1 1
1 2 3 4 5
1 3 6 10 15
1 4 10 20 35
1 5 15 35 70
*/

#include<stdio.h>

void main() {
	int arr[5][5] = {
		{1,1,1,1,1},
	};
	int i, j;

	for (i = 1; i < 5; i++) {
		arr[i][0] = 1;
		for (j = 1; j < 5; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}