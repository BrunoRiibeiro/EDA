#include <stdio.h>

int find_last_char(char *v) {
	int acc = 0;
	for (int i = 0; i < 1004; i++) {
		if (v[i] != '\0') {
			acc++;
		} else {
			return acc;
		}
	}
}

int main() {
	int l, x, y, rx, ry, hf;
	char c, str[1004][1004];
	scanf("%d", &l);

	for (int i = 1; i <= l; i++) {
		scanf(" %1000[^\n]s", str[i]);
	}

	scanf("%d %d",&x, &y);
	rx = x;
	ry = y;
	while (scanf("\n%c", &c) != EOF) {
		if (c == 'j') {
			if (rx + 1 <= l) {
				rx += 1;
				hf = find_last_char(str[rx]);
				if ((ry > hf) || (ry < hf && hf < y)) {
					ry = hf;
				} else {
					ry = y;
				}
			}
		}
		if (c == 'k') {
			if (rx > 1) {
				rx -= 1;
				hf = find_last_char(str[rx]);
				if (ry > hf || (ry < hf && hf < y)) {
					ry = hf;
				} else {
					ry = y;
				}
			}
		}
		printf("%d %d %c\n", rx, ry, str[rx][ry - 1]);
	}
	return 0;
}
