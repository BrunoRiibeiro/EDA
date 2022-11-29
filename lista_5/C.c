#include <stdio.h>

void backward_string(char *str) {
	if (*str == '\0')
		return;

	backward_string(str + 1);
	printf("%c", *str);
}

int main() {
	char str[501];
	scanf("%s", str);
	backward_string(str);
	printf("\n");
	return 0;
}
