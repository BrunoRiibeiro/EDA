#include <stdio.h>
#include <stdlib.h>
#define less(a, b) (a < b)
#define exch(a, b) {int t = a; a = b; b = t;}
#define cmpexch(a, b) {if (less(b, a)) exch(a, b); }

int partition(int *v, int l, int r) {
	int c = v[r], i = l-1, j = r;
	for ( ; ; ) {
		while (less(v[++i], c));
		while (less(c, v[--j])) if (j == l) break;
		if (i >= j) break;
		exch(v[i], v[j]);
	}
	exch(v[i], v[r]);
	return i;
}

void quicksort(int *v, int l, int r) {
	if (r <= l) return;
	cmpexch(v[(l+r)/2], v[r]);
	cmpexch(v[l], v[(l+r)/2]);
	cmpexch(v[r], v[(l+r)/2]);
	int j = partition(v, l, r);
	quicksort(v, l, j-1);
	quicksort(v, j+1, r);
}

int main() {
	int n, *ns;
	scanf("%d", &n);
	ns = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ns[i]);
	quicksort(ns, 0, n-1);
	printf("%d", ns[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", ns[i]);
	printf("\n");
	return 0;
}
