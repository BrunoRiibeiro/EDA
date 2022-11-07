#include <stdio.h>

int main() {
	int a, b, c, t;
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &t);
	if (a + b + c == t) {
		printf("Acertou\n");
	} else {
		printf("Errou\n");
	}
	return 0;
}
