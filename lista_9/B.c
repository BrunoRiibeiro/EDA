#include <stdio.h>

typedef int Item;

#define less(a, b) (a < b)
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
	Item lst[1000], n = 0;
	while (scanf("%d", &lst[n]) != EOF)
		n++;
	selectionsort(lst, 0, n-1);
	printf("%d", lst[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", lst[i]);
	printf("\n");
	return 0;
}
