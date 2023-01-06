#include <stdio.h>

int main() {
	unsigned char n, a[101], b[101], ag = 0, bg = 0, r = 0;
	scanf("%hhu", &n);
	scanf("%s", a);
	scanf("%s", b);
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] == 'o')
			ag++;
		r++;
		if (ag > bg + (n - i) + 1 || bg > ag + (n - i)) {
			printf("%hhu\n", r);
			break;
		} if (b[i - 1] == 'o')
			bg++;
		r++;
		if (ag > bg + (n - i) || bg > ag + (n - i)) {
			printf("%hhu\n", r);
			break;
		}
	}
	if (ag == bg)
		printf("Empate\n");
	return 0;
}
