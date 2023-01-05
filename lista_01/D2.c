#include <stdio.h>
#include <string.h>

int main() {
	int acc = 0, sacc = 0, nf = 0;
	char str[3];

	while (scanf("%s", str) != EOF) {
		acc++;
		if (!strcmp(str, "sim")) {
			sacc++;
		}
		if (acc == 10) {
			if (sacc >= 2) {
				nf++;
			}
			sacc = 0;
			acc = 0;
		}
	}
	printf("%d\n", nf);
	return 0;
}
