/* 양의 정수를 입력 받아, 각 자리의 수를 높은 자릿수부터 차례로 출력하는 프로그램을 작성하시오*/
#include <stdio.h>

int sum(int n) {
	if (n <= 1){
		return 1;
	}
	else if(n>=2) {
		return n + sum(n - 1);
	};
}

int main() {
	int result;
	int n;
	scanf_s("%d", &n);
	result = sum(n);
	printf("%d", result);
	return 0;
}
