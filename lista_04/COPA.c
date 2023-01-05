#include <stdio.h>

int main() {
	unsigned char t;
	unsigned short n;
	while (scanf("%hhu %hu", &t, &n) && t != 0) {
		unsigned short p, pacc = 0;
		for (int i = 0; i < t; i++) {
			scanf("%*s %hu", &p);
			pacc += p;
		}
		printf("%hu\n", (n * 3) - pacc);
	}
	return 0;
}
