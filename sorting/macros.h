typedef int Item;
#define less(A,B) ((A) < (B))
#define exch(A,B) { Item t = A; A = B; B = t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
