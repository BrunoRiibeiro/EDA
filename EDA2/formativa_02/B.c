#include <stdio.h>
#include <stdlib.h>

int main() {
	char c, *m = malloc(sizeof(char) * (unsigned int) 1<<31);
	unsigned int s, from = (unsigned int) 1<<31;
	while (scanf("%u %c", &s, &c) != EOF) {
		m[s] = c;
		if (s < from)
			from = s;
	} while (m[from])
		printf("%c", m[from++]);
	printf("\n"); free(m);
	return 0;
}
