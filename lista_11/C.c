#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int qnt;
} Item;

#define exch(a,b) {Item t = a; a = b; b = t;}

int binarysearch(Item *v, int l, int r, int n) {
    while (l <= r) {
        int m = l + (r-l)/2;
        if (n == v[m].num)
            return m;
        if (n < v[m].num)
            l = m+1;
        else
            r = m-1;
    }
	return -1;
}

void insertionsort(Item *v, int l, int r) {
    for (int i = r; i > l; i--)
        if (v[i].qnt > v[i-1].qnt)
            exch(v[i], v[i-1]);
    for (int i = l+2; i <= r; i++){
        int j = i;
        Item m = v[j];
        while (m.qnt > v[j-1].qnt) {
            v[j] = v[j-1];
            j--;
        }
        v[j] = m;
  }
}

void merge(Item *v, int l, int r, int m) {
    Item *v2 = malloc(sizeof(Item) * (r-l+1));
    int i = l, j = m+1, k = 0;
    while (i <= m && j <= r) {
        if (v[i].num > v[j].num)
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++];
    }
    while (i <= m)
        v2[k++] = v[i++];
    while (j <= r)
        v2[k++] = v[j++];
    k = 0;
    for (int i = l; i <= r; i++)
        v[i] = v2[k++];
    free(v2);
}

int main() {
    int s, f, e, vote, i = 0, invalid = 0, l = 0;
    Item v[150000];
    scanf("%d %d %d", &s, &f, &e);
    while (scanf("%d", &vote) == 1){
        if (vote < 0)
            invalid ++;
        else if (vote > 0){
            l++;
            int x = binarysearch(v, 0, i-1, vote);
            if (x == -1) {
                v[i].num = vote;
                v[i].qnt = 1;
                merge(v, 0, i, i-1);
                i++;
            } else
                v[x].qnt ++;
        }
    }
    printf("%d %d\n", l, invalid);
    int m = 0, n, p, q, j = 0;
    while (v[j].num/10000 != 0)
        j++;
    insertionsort(v, 0, j-1);
    n = j;
    while (v[j].num/1000 != 0)
        j++;
    insertionsort(v, n, j-1);
    p = j;
    while (v[j].num/100 != 0)
        j++;
    insertionsort(v, p, j-1);
    q = j;
    insertionsort(v, q, i-1);
    int y = v[q].qnt * 100;
    int sum = 0;
    while (j < i) {
        sum = sum + v[j].qnt;
        j++;
    }
    y = y / sum;
    if (y > 50)
        printf("%d\n", v[q].num);
    else
        printf("Segundo turno\n");
    for (int k = p; k < (p+s); k++)
        printf("%d ", v[k].num);
    printf("\n");
    for (int k = n; k < (n+f); k++)
        printf("%d ", v[k].num);
    printf("\n");
    for (int k = 0; k < e; k++)
        printf("%d ", v[k].num);
    printf("\n");
    return 0;
}
