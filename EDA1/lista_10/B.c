#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(a, b) (a < b)

void merge(Item *v, int l, int r1, int r2) {
	Item *v2 = malloc(sizeof(Item) * (r2 - l + 1));
	int k = 0, i = l, j = r1+1;
	while (i <= r1 && j <= r2) {
		if (less(v[i], v[j]))
			v2[k++] = v[i++];
		else
			v2[k++] = v[j++];
	}
	while (i <= r1)
		v2[k++] = v[i++];
	while (j <= r2)
		v2[k++] = v[j++];
	k = 0;
	for (int i = l; i <= r2; i++)
		v[i] = v2[k++];
}

void mergesort(Item *v, int l, int r) {
	if (l >= r) return;
	int avg = l + (r - l) / 2;
	mergesort(v, l, avg);
	mergesort(v, avg+1, r);
	merge(v, l, avg, r);
}

int main() {
	int n;
	scanf("%d", &n);
	Item lst[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &lst[i]);
	mergesort(lst, 0, n-1);	
	printf("%d", lst[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", lst[i]);
	printf("\n");
	return 0;
}
