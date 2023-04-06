#include <stdio.h>
#include <stdlib.h>

int sum_of_digits(char *n, int s) {
	if (*n == '\0') {
		return s;
	}
	s += (*n - '0');
	sum_of_digits(n + 1, s);
}	

char *itoa(int n) {
	int m = n, i = 0;
	while (m != 0) {
		i++;	
		m /= 10;
	}
	char *c;
	char array[i];
	c = (char*)malloc(i);
	int index = 0;
	while (n != 0) {
		array[++index] = n % 10 + '0';
		n /= 10;
	}
	for (int i = 0; i < index; i++) {
		c[i] = array[index - i];
	}
	array[i] = '\0';
	return (char*) c;
}

void mod9(char *n, char *cons, int i) {
	int s = sum_of_digits(n, 0);
	i++;
	if (s == 9) { 
		printf("%s is a multiple of 9 and has 9-degree %d.\n", cons, i);
	} else if (s > 9) {
		mod9(itoa(s), cons, i);
	} else if (s < 9) {
		printf("%s is not a multiple of 9.\n", cons);
	}
}

int main() {
	char n[1001];
	while (scanf("%s", n) && *n != '0') {
		mod9(n, n, 0);	
	}
	return 0;
}
