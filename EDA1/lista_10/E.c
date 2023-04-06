#include <stdio.h>
#include <stdlib.h>
#define lesseq(a, b) (a <= b)

void merge(int *v, int l, int m, int r) {
	int *v2 = malloc(sizeof(int) * (r - l + 1));
	int k = 0, i = l, j = m+1;
	while (lesseq(i, m) && lesseq(j, r)) {
		if (lesseq(v[i], v[j]))
			v2[k++] = v[i++];
		else
			v2[k++] = v[j++];
	}
	while (lesseq(i, m))
		v2[k++] = v[i++];
	while (lesseq(j, r))
		v2[k++] = v[j++];
	k = 0;
	for (int i = l; i <= r; i++)
		v[i] = v2[k++];
	free(v2);
}

void mergesort(int *v, int l, int r) {
	if (l >= r) return;
	int m = l + (r - l) / 2;
	mergesort(v, l, m);
	mergesort(v, m+1, r);
	merge(v, l, m, r);
}

int binarysearch(int *v, int l, int r, int n) {
	if (l <= r) {
		int m = l + (r - l) / 2;
		if (v[m] == n)
			return m;
		else if (n < v[m])
			return binarysearch(v, l, m-1, n);
		else
			return binarysearch(v, m+1, r, n);
	}
	return -1;
}

int main() {
	int n, num, *p;
	scanf("%d", &n);
	p = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	mergesort(p, 0, n-1);
	while (scanf("%d", &num) != EOF) {
		int var = binarysearch(p, 0, n-1, num);
		printf("%s\n", var == -1 ? "nao" : "sim");
	}
	return 0;
}
