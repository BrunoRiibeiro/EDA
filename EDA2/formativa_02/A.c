#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned short acc = 0, numb = 0, *grades = calloc(1000, sizeof(unsigned short));
	unsigned int n = 0;
	scanf("%u", &n);
	for (unsigned int i = 0; i < n; i++) {
		scanf("%hu", &numb);
		grades[numb]++;
	} for (unsigned short i = 0; i < 1000; i++)
		if (grades[i] >= acc) {
			acc = grades[i];
			numb = i;
		}
	printf("%hu\n", numb);
	free(grades);
	return 0;
}
