#include <stdio.h>

typedef long Item;

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}

void selectionsort(Item *v, int l, int r) {
	for (int i = l; i < r; i++) {
		int min = i;
		for (int j = i+1; j <= r; j++) {
			if (less(v[j], v[min]))
				min = j;
		}
		exch(v[min], v[i]);
	}
}

int main() {
	Item lst[1001], n = 0;
	while (scanf("%ld", &lst[n]) != EOF)
		n++;
	selectionsort(lst, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%ld ", lst[i]);
	printf("\n");
	return 0;
}
