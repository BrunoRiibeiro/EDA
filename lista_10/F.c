#include <stdio.h>
#include <stdlib.h>
#define lesseq(a, b) (a <= b)

int * merge2(int *v1, int l1, int r1, int *v2, int l2, int r2) {
	int *v3 = malloc(sizeof(int) * ((r1 - l1 + 1) + (r2 - l2 + 1)));
	int v3i = 0, v1i = l1, v2i = l2;
	while (lesseq(v1i, r1) && lesseq(v2i, r2)) {
		if (lesseq(v1[v1i], v2[v2i]))
			v3[v3i++] = v1[v1i++];
		else
			v3[v3i++] = v2[v2i++];
	}
	while (lesseq(v1i, r1))
		v3[v3i++] = v1[v1i++];
	while (lesseq(v2i, r2))
		v3[v3i++] = v2[v2i++];
	return v3;
}

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
		else if (v[m] > n)
			return binarysearch(v, l, m-1, n);
		else
			return binarysearch(v, m+1, r, n);
	}
	return -1;
}

int clean(int *v, int l, int r) {
	int j = l;
	for (int i = 1; i <= r; i++) {
		if (v[i] != v[j])
			v[++j] = v[i];
	}
	return j;
}

int main() {
	int n, *x, *nmu, j = -1;
	scanf("%d", &n);
	x = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	mergesort(x, 0, n-1);
	int r = clean(x, 0, n-1);
	if (r % 2 == 0)
		x[++r] = 1000000000;
	nmu = malloc(sizeof(int) * (r / 2 + 1));
	for (int i = 0; i < r; i += 2) {
		nmu[++j] = x[i] + x[i+1];
		if (binarysearch(x, 0, r, nmu[j]) != -1)
			j--;
	}
	int *fx = merge2(x, 0, r, nmu, 0, j); free(nmu); free(x);
	for (int i = 0; i <= r+j+1; i += 4)
		printf("%d\n", fx[i]);
	printf("Elementos: %d\n", r+j+2);
	return 0;
}
