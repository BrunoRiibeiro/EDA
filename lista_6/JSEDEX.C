#include <stdio.h>

int main() {
	unsigned short n, a, l, p;
	scanf("%hu", &n);
	scanf("%hu %hu %hu", &a, &l, &p);
	if (n > a || n > l || n > p) {
		printf("N\n");
	} else {
		printf("S\n");
	}
	return 0;
}
