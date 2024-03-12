#include "macros.h"

void insertionsort(Item *v, int l, int r) {
	for (int i = r; i > l; i--)
		cmpexch(v[i-1], v[i]);
	for (int i = l+2; i <= r; i++) {
		int j = i; Item hand = v[j];
		while (less(hand, v[j-1]))
			v[j] = v[j-1], j--;
		v[j] = hand;
	}
}
