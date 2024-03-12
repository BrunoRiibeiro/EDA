#include "macros.h"

void bubblesort(Item *v, int l, int r) {
	for (int i = l; i < r; i++)
		for (int j = l; j < r; j++)
			cmpexch(v[j], v[j+1]);
}

void bubblesort_sentinel(Item *v, int l, int r) {
	for (int i = l; i < r; i++) {
		char sentinel = 0;
		for (int j = l; j < r; j++) {
			if (less(v[j+1], v[j])) {
				exch(v[j], v[j+1]);
				sentinel = 1;
			} if (!sentinel) break;
		}
	}
}
