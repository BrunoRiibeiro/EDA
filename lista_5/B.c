#include <stdio.h>

void switch_x_y(char *str) {
	if (*str == '\0') {
		printf("\n"); 
		return;
	}
	else if (*str == 'x')
		printf("%c", 'y');
	else if (*str == 'X')
		printf("%c", 'Y');
	else
		printf("%c", *str);
	
	switch_x_y(str + 1);
}

int main() {
	char str[81];
	scanf("%s", str);
	switch_x_y(str);
	return 0;
}
