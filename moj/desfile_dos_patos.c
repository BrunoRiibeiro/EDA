#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned short n;
	scanf("%hu", &n);
	while (n) {
		unsigned int colour; unsigned short acc = 0, *ai = calloc(1000001, sizeof(unsigned int));
		for (unsigned short i = 0; i < n; i++) {
			scanf("%u", &colour);
			ai[colour]++;
		} for (unsigned int i = 1; i < 1000001; i++)
			if (ai[i] > acc) {
				acc = ai[i];
				colour = i;
			}
		printf("%u\n", colour);
		scanf("%hu", &n);
		free(ai);
	}
	return 0;
}
