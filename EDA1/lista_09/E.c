#include <stdio.h>

typedef struct {
	int key;
	char word[16];
}Item;
#define key(a) (a.key)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}

int binarysearch(Item *v, int l, int r, int t) {
	if (l <= r) {
		int mean = l + (r - l) / 2;
		if (key(v[mean]) == t)
			return mean;
		else if (t < key(v[mean]))
			return binarysearch(v, l, mean-1, t);
		else
			return binarysearch(v, mean+1, r, t);
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
	int n, temp;
	scanf("%d", &n);
	Item lst[n];
	for (int i = 0; i < n; i++)
		scanf("%d %s", &lst[i].key, lst[i].word);
	selectionsort(lst, 0, n-1);
	while (scanf("%d", &temp) != EOF) {
		int var = binarysearch(lst, 0, n-1, temp);
		printf("%s\n", var == -1 ? "undefined" : lst[var].word);
	}
	return 0;
}
