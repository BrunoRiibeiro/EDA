#include <stdio.h>

int main() {
	int r = 0, day = 0;
	int cs[200][2];

	while (scanf("%d", &r) != EOF) {
		int c = 0, s = -1;
		for (int i = 0; i < r; i++) {
			scanf("%d %d", &(cs[i][0]), &(cs[i][1]));
		}
		for (int i = 0; i < r; i++) {
			if (cs[i][1] > s) {
				s = cs[i][1];
				c = cs[i][0];
			}
			else if (cs[i][1] == s) {
				if (cs[i][0] < c) {
					c = cs[i][0];
				}
			}
		}
		day++;
		printf("Dia %d\n", day);
		printf("%d\n\n", c);
	}

	return 0;
}
