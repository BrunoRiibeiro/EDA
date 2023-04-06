#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct Stack {
	Item *v;
	int size, top;
}Stack;

int create_stack(Stack *p, int s) {
	p->size = s;
	p->v= malloc(s * sizeof(Item));
	p->top = 0;
	return 1;
}

int push(Stack *p, Item e) {
	if (p->top == p->size) return 0;
	p->v[p->top++] = e;
	return 1;
}

void pull(Stack *p) {
	p->top--;
}

Item top(Stack *p) {
	return p->v[p->top-1];
}

int is_empty(Stack *p) {
	return p->top == 0;
}

int main() {
	int n;
	while (scanf("%d", &n) && n != 0) {
		Item lst[n];
		for (int i = 0; i < n; i++) 
			scanf("%d", &lst[i]);
		Stack wait;
		create_stack(&wait, n);
		int i = 0, seq = 1;
		while (i < n) {
			while (!is_empty(&wait) && top(&wait) == seq) {
				seq++;
				pull(&wait);
			} 
			if (lst[i] != seq)
				push(&wait, lst[i]);
			else
				seq++;
			i++;
		}
		while (!is_empty(&wait) && top(&wait) == seq) {
			seq++;
			pull(&wait);
		}
		printf("%s\n", seq-1 == n ? "yes" : "no");
	}	
	return 0;
}
