#include <stdio.h>

int sum_of_digits(char *n, int s) {
	if (*n == '\0') {
		return s;
	}
	s += (*n - '0');
	return sum_of_digits(n + 1, s);
}

int main() {
	char n[14];
	scanf("%s", n);
	printf("%d\n", sum_of_digits(n, 0));
	return 0;
}
