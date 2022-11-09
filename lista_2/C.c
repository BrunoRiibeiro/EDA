#include <stdio.h>

int main() {
	int h;
	while (scanf("%x", &h) != EOF) {
		char *p = &h;
		for (int i = 0; i < 4; i++) {
			if (p[i] == 0) {
				printf("\n");
				return 0;
			}
			printf("%c", p[i]);
		}
	}
}
