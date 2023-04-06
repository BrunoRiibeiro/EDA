#include <stdio.h>
#include <stdlib.h>
#define key(A) (A.curr)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if (less(B,A)) exch(A,B);}

typedef struct Item {
    unsigned long long back, curr, next;
}Item;

int partition(Item *v, int l, int r) {
    int i = l-1, j = r;
    Item c = v[r];
    for ( ; ; ) {
        while (less(v[++i], c));
        while (less(c, v[--j])) if (j == l) break;
        if (i >= j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quicksort(Item *v, int l, int r) {
    if (r <= l) return;
    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);
    int j = partition(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

int binarysearch(Item *v, int l, int r, unsigned long long n) {
    if (l <= r) {
        int m = l + (r - l) / 2;
        if (n == key(v[m]))
            return m;
        else if (n > key(v[m]))
            return binarysearch(v, m+1, r, n);
        else
            return binarysearch(v, l, m-1, n);
    }
    return -1;
}

int is_sane(Item *v, int n, Item back, Item target) {
    if (back.next == target.curr && target.back == back.curr) return 1;
    int i = binarysearch(v, 0, n, back.next);
    if (i == -1 || v[i].back != back.curr) return 0;
    return is_sane(v, n, v[i], target);
}

int main() {
    Item *v = malloc(sizeof(Item) * 500000);
    int n = 0;
    for (n; scanf(" %llx %llx %llx", &v[n].curr, &v[n].back, &v[n].next) == 3; n++);
    Item ptr1 = v[0], ptr2 = v[1];
    quicksort(v, 0, n);
    printf("%s\n", (is_sane(v, n, ptr1, ptr2) ? "sana" : "insana"));
    return 0;
}
