#include <stdio.h>

typedef int Item;
int loc;

int binarysearch(Item *v, int l, int r, int n) {
	if (l <= r) {
		int m = l + (r - l) / 2;
		if (n == v[m])
			return m;
		else if (n > v[m]) {
			loc = m+1;
			return binarysearch(v, m+1, r, n);
		} else {
			loc = m;
			return binarysearch(v, l, m-1, n);
		}
	}
	return -1;
}

int main() {
	unsigned int n, m;
	scanf("%u %u", &n, &m);
	Item lstn[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &lstn[i]);
	for (int i = 0; i < m; i++) {
		int ms, var;
		scanf("%d", &ms);
		var = binarysearch(lstn, 0, n-1, ms);
		if(var == -1)
			printf("%d\n", loc);
		else
			printf("%d\n", var);
	}
	return 0;
}
