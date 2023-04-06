#include <stdio.h>

int main() {
	int n, v[100], lst[100], length = 0, sum = 0, acc = 0, lst_length = 0;
	while(scanf("%d", &n) && n != 0) {
		v[length] = n;
		length++;
	}
	scanf("%d", &sum);

	for (int i = 0; i < length; i++) {
		acc += v[i];
		if (acc > sum) {
			lst[lst_length] = v[i];
			lst_length++;
			acc = 0;
		}
	}
	for (int i = lst_length - 1; i >= 0; i--) {
		printf("%d\n", lst[i]);
	}
	return 0;
}
