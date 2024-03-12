#include "macros.h"

void selectionsort(Item *v, int l, int r) {
	for (int i = l; i < r; i++) {
		int min = i;
		for (int j = i+1; j <= r; j++)
			if (less(v[j], v[min]))
				min = j;
		exch(v[i], v[min]);
	}
}

void selectionsortR(Item *v, int l, int r) {
	if (l == r) return;
	int min = l;
	for (int j = l+1; j <= r; j++)
		if (less(v[j], v[min]))
			min = j;
	exch(v[min], v[l]);
	selectionsortR(v, l+1, r);
}
