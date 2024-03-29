#include <stdio.h>
#include <stdlib.h>

/*--- base가 가리키는 요소의 크기가 size이고 요소의 개수가 nmemb인 배열에서 key와 일치하는 요소를
	  비교 함수 compar을 사용하여 이진 검색 ---*/
void* binsearch(const void* key, const void* base, size_t nmemb, size_t size,
	int(*compar)(const void*, const void*))
{
	int pl = 0; // 검색 범위 맨 앞의 인덱스
	int pr = nmemb - 1; // 검색 범위 맨 끝의 인덱스
	int pc; // 검색 범위 한가운데의 인덱스
	char* x = (char*)base;

	if (nmemb > 0) { // 요소의 개수가 1개 이상이라면
		while (1) {
			int comp = compar((const void*)&x[(pc = (pl + pr) / 2) * size], key);
			if (comp == 0) // 검색 성공(x[pc] == key)
				return &x[pc * size];
			else if (pl == pr) // 요소가 존재하지 않음(앞뒤가 같아짐)
				break;
			else if (comp < 0)  // x[pc] < key
				pl = pc + 1; // 검색 범위를 후반부로 좁혀감
			else // x[pc] > key
				pr = pc - 1; // 검색 범위를 전반부로 좁혀감
		}
	}
	return NULL; // 검색 실패 
}

/*--- 정수를 비교하는 함수 ---*/
int int_cmp(const int* a, const int* b) {
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

void main(void){
	int i, nx, ky;
	int* x; // 배열의 첫 번째 요소에 대한 포인터 
	int* p; // 검색된 요소에 대한 포인터

	puts("binsearch 함수를 사용하여 검색");
	printf("요솟수 : ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int)); // 요소의 개수 nx인 int형 배열을 생성 

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("검색 값 : ");
	scanf("%d", &ky);

	p = binsearch(&ky, // 검색 값에 대한 포인터 
		x, // 배열 
		nx, // 요소의 개수 
		sizeof(int), // 요소의 크기
		(int(*)(const void*, const void*))int_cmp // 비교 함수
	);

	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, (int)(p - x));
	free(x); // 메모리 해제
}
