#include <stdio.h>

int main() {
	unsigned short r = 0, t;
	unsigned char n;
	scanf("%hhu", &n);
	for (unsigned char i = 0; i < n; i++) {
		unsigned short c = 0;
		scanf("%hu", &c);
		r += c;
	}
	scanf("%hu", &t);
	if (r == t) {
		printf("Acertou\n");
	} else {
		printf("Errou\n");
	}
	return 0;
}
