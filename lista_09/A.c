#include <stdio.h>

typedef int Item;

#define less(a, b) (a < b)
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) {if (less(b, a)) exch(a, b);}

void bubblesort(Item *v, int l, int r) {
	for (int i = l; i < r; i++) {
		for (int j = l; j < r-i; j++)
			cmpexch(v[j], v[j+1]);
	}
}

int main() {
	Item lst[1000], n = 0;
	while(scanf("%d", &lst[n]) != EOF)
		n++;
	bubblesort(lst, 0, n-1);
	printf("%d", lst[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", lst[i]);
	printf("\n");
	return 0;
}
