#include <stdio.h>

void mv_x(char *str) {
	if (*str == '\0') {
		return;
	} else if (*str == 'x') {
		mv_x(str + 1);
		printf("%c", *str);
	} else {
		printf("%c", *str);
		mv_x(str + 1);
	}
}

int main() {
	char str[101];
	scanf("%s", str);
	mv_x(str);
	printf("\n");
	return 0;
}
