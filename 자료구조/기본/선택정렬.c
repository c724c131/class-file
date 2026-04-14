#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/*int A[] 도 가능하죠*/
void print(int *A) {
	for (int i = 0; i < 10; i++) {
		printf("%d ", *(A + i));
	}
	printf("\n");
}

void ABC(int A[], int k) {
	int max = k;

	for (int i = k + 1; i < 10; i++) {
		if (A[i] > A[max]) {
			max = i;
		}
	}
	int temp = A[max];
	A[max] = A[k];
	A[k] = temp;
}

int main(void) {
	int arr[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
	}
	
	print(arr);
	printf("=================================\n");

	for (int i = 0; i < 9; i++) {
		ABC(arr, i);
		print(arr);
	}
	/*for 문을 함수 안으로 넣으면 선택정렬 함수가 된다.*/
	return 0;
}

/*수정 필요*/
