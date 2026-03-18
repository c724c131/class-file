#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char from, char temp, char to) {
	if (n == 1)
		printf("%d : %c -> %c\n", n, from, to);
	else {
		hanoi(n - 1, from, to, temp);
		printf("%d : % c -> % c\n", n, from, to);
		hanoi(n - 1, temp, from, to);
	}
}

int main() {
	hanoi(4, 'A', 'B', 'C');
	return 0;
}
