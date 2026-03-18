#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rMax(int arr[], int n) {
	if (n == 1)
		return arr[0];

	int M = rMax(arr, n - 1);
	if (arr[n-1] >= M)
		return arr[n-1];
	else 
		return M;
}

int main() {
	int N;
	scanf_s("%d",&N);
	int* arr = (int*)malloc(sizeof(int) * N); ///메모리 할당 방식 잘 알아두기

	for (int i = 0; N > i; i++) {
		scanf_s("%d", (arr + i)); ///그냥 띄어쓰기 해도 연속으로 입력됨
	}

	for (int i = 0; N > i; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n%d", rMax(arr, N));

	free(arr);
	return 0;
}
