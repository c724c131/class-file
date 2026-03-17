/*5개의 값중 가장 큰 값을 찾기 위해 4개중 가장 큰값 -> 3개중 -> 2개중 -> 1개*/
/*첫 호풀스텍 rMax(A,5) -> rMax(A,4) -> rMax(A,3) -> rMax(A,2) -> rMax(A,1) -> returmn*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rMax(int A[], int n) {
	if (n == 1) {
		return A[0];
	}
	int m = rMax(A, n - 1);

	if (A[n - 1] > m)
		return A[n - 1];
	else
		return m;
}

int main() {
	int n;
	scanf_s("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Max : %d\n", rMax(arr, n));
	return 0;
}
