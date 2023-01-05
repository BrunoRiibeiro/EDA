#include <stdio.h>

unsigned long f91(unsigned long n) {
	if (n >= 101) {
		return n - 10;
	} else if (n <= 100) {
		return f91(f91(n + 11));
	}
}

int main() {	
	unsigned long n = 1;
	while (scanf("%lu", &n) && n != 0) {
		printf("f91(%lu) = %lu\n", n, f91(n));
	}
	return 0;
}
