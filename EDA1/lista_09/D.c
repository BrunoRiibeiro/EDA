#include <stdio.h>

typedef struct {
	int origin, order;
} Item;
#define key(a) (a.order)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}

int binarysearch(Item *v, int l, int r, int n) {
	if (l <= r) {
		int m = l + (r - l) / 2;
		if (v[m].order == n)
			return m;
		else if (n < v[m].order)
			return binarysearch(v, l, m-1, n);
		else
			return binarysearch(v, m+1, r, n);
	}
	return -1;
}

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
	unsigned long n, m;
	scanf("%ld %ld", &n, &m);
	int lstm[m];
	Item lstn[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &lstn[i].order);
		lstn[i].origin = i;
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &lstm[i]);
	selectionsort(lstn, 0, n-1);
	for (int i = 0; i < m; i++) {
		int var = binarysearch(lstn, 0, n-1, lstm[i]);	
		if (var == -1)
			printf("%d\n", -1);
		else 
			printf("%d\n", lstn[var].origin);
	}
	return 0;
}
