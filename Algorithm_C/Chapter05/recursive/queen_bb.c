/* 각 행, 각 열에 1개의 퀸을 배치하는 조합을 재귀적으로 나열하기 */
#include<stdio.h>

int flag[8]; // 각 행에 퀸을 배치했는지 체크하는 배열
int pos[8]; // 각 열에서 퀸의 위치

/* 각 열에서 퀸의 위치를 출력 */
void print(void) {
	int i;
	for (i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

// i열에서 알맞은 위치에 퀸을 배치
void set(int i) {
	int j;
	for (j = 0; j < 8; j++) {
		if (!flag[j]) { // j행에 퀸을 배치하지 않았다면 
			pos[i] = j;
			if (i == 7) // 모든 열에 배치를 완료
				print();
			else {
				flag[j] = 1; // 퀸을 배치한 후 flag값으로 1 배열
				set(i + 1);
				flag[j] = 0;

			}
		}
	}
}

void main() {
	int i;
	for (i = 0; i < 8; i++)
		flag[i] = 0;
	set(0);
}

