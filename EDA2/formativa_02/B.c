#include <stdio.h>
#include <stdlib.h>

int main() {
	char c, *m = malloc(sizeof(char) * (unsigned long) 1<<31);
	unsigned long s, from = (unsigned long) 1<<31;
	while (scanf("%lu %c", &s, &c) != EOF) {
		m[s] = c;
		if (s < from)
			from = s;
	} while (m[from])
		printf("%c", m[from++]);
	printf("\n");
	return 0;
}
