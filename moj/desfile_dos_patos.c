#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned short n;
	scanf("%hu", &n);
	while (n) {
		unsigned int colour, mcolour; unsigned short acc = 0, *ai = calloc(1000001, sizeof(unsigned int));
		for (unsigned short i = 0; i < n; i++) {
			scanf("%u", &colour);
			if (++ai[colour] > acc) {
				acc = ai[colour];
				mcolour = colour;
			}
		}
		printf("%u\n", mcolour);
		scanf("%hu", &n);
		free(ai);
	}
	return 0;
}
