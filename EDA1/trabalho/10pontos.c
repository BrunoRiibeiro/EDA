#include <stdio.h>

typedef long Item;
#define less(A,B) (A < B)
#define exch(A,B){Item t = A; A = B; B = t;}
#define compexch(A,B) {if (less(B,A)) exch(A,B);}

void insertionsort(Item *v, int l, int r) { 
	compexch(v[l], v[r]);
	for (int i = l+2; i <= r; i++) {
		int j = i; 
		Item m = v[j];
		while (less(m, v[j-1])) {
			v[j] = v[j-1];
			j--;
		}
		v[j] = m;
	}
}

int main() {
	Item v[102], traffic_sign;
	int op, i = 0;
	while (scanf("%d %ld", &op, &traffic_sign) == 2) {
		if (op == 1) {
			if (i < 101) {
				v[i++] = traffic_sign;
				insertionsort(v, 0, i-1);
			} else {
			Item aux = traffic_sign;
				if (less(traffic_sign, v[100])) {
					exch(traffic_sign, v[100]);
					insertionsort(v, 0, 100);
				}
			}
		} else {
			int n = traffic_sign;
			for (int j = 0; j < n; j++)
				printf("%ld ", v[j]);
			printf("\n");
		}
	}
	return 0;
}
