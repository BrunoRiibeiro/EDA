#include <stdio.h>

int main(void) {
	int acc = 0;
	int x;
	while(scanf("%d", &x) != EOF) {
		acc++;
	}	
	printf("%d\n", acc);
}
