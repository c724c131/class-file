#include <stdint.h>
#include <stdlib.h>
#define INT_MAX 256

typedef unsigned int Nat_Number;

Nat_Number zero() {
	return 0;
}

Nat_Number successor(Nat_Number x) {
	if (x == INT_MAX)
		return INT_MAX;
	else
		return x + 1;
}

int equal(Nat_Number x, Nat_Number y) {
	if (x == y)
		return 1;
	else
		return 0;
}

Nat_Number add(Nat_Number x, Nat_Number y) {
	if (x > INT_MAX - y)
		return INT_MAX;
	else
		return x + y;
}

Nat_Number sub(Nat_Number x, Nat_Number y) {
	if (x < y)
		return 0;
	else
		return x - y;
}

int main() {
	return 0;
}
