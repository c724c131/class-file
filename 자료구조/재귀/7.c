#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rCountChar(char str[], char c, int i) {

	int cnt = (str[i] == c) ? 1 : 0;

	if (i == 0)
		return cnt;
	else
		return cnt + rCountChar(str, c, i - 1);
}

int main() {
	char str[100], c;
	scanf_s("%s", str, (int)sizeof(str));
	scanf_s(" %c", &c, sizeof(c));

	printf("%d\n", rCountChar(str, c, sizeof(c)/sizeof(char));
}
