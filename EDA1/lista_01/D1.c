#include <stdio.h>
#include <string.h>

int main(void) {
	char str[30];
	int acc = 0;
	while (scanf("%s", str) != EOF) {
		if (!strcmp(str, "marte")) {
			acc++;
			printf("Leonardo Cicero Marciano\n");
		}
	}
	if (acc == 0) {
		printf("none\n");
	}
}
