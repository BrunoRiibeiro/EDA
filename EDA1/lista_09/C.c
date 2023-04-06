#include <stdio.h>

typedef int Item;

#define less(a, b) (a < b)
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) {if (less(b, a)) exch(a, b);}

void insertionsort(Item *v, int l, int r) {
	for (int i = r; i > l; i--)
		cmpexch(v[i-1], v[i]);
	for (int i = l+2; i <= r; i++) {
		int j = i;
		Item temp = v[j];
		while (less(temp, v[j-1])) {
			v[j] = v[j-1];
			j--;
		}
		v[j] = temp;
	}
}

int main() {
	Item lst[50000], n = 0;
	while (scanf("%d", &lst[n]) != EOF)
		n++;
	insertionsort(lst, 0, n-1);
	printf("%d", lst[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", lst[i]);
	printf("\n");
	return 0;
}
