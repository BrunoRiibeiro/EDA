#include <stdio.h>
#include <stdlib.h>
#define lesseq(a, b) (a <= b)

int n[16 * (int)1e5 + (int)6.66];

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
    for (int i = 0; i <= r - l; i++)
        v[i] = v2[k++];
    free(v2);
}

int main() {
    int s, acc = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &s);
        for (int j = 0; j < s; j++)
            scanf("%d", &n[acc+j]);
        merge(n, 0, acc-1, acc+s-1);
        acc += s;
    }
    for (int i = 0; i < acc; i++)
        printf("%d ", n[i]);
    printf("\n");
    return 0;
}