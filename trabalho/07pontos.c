#include <stdio.h>
#include <stdlib.h>

typedef char Item;
typedef struct Stack {
	Item *v;
	int size, top;
}Stack;

int create_stack(Stack *p, int s) {
	p->v = malloc(sizeof(Item) * s);
	if (p->v == NULL) return 0;
	p->size = s;
	p->top = 0;
	return 1;
}

int push(Stack *p, Item e) {
	if (p->size == p->top) return 0;
	p->v[p->top++] = e;
	return 1;
}

void pull(Stack *p) {
  p->top--;
}

int is_empty(Stack *p) {
	return p->top == 0;
}

Item top(Stack *p) {
	return p->v[p->top-1];
}

int main() {
	int t;
	scanf("%d", &t);
	Stack p;
	create_stack(&p, t*100002);
	for (int i = 0; i < t; i++) {
		char str[100002];
		scanf(" %[^\n]", str);
		int j = 0;
		while (str[j] != '\0') {
			if (str[j] == '*'|| str[j] == '/' || str[j] == '_')
				if (is_empty(&p))
					push(&p, str[j]);
				else if (top(&p) == str[j])
					pull(&p);
				else
					push(&p, str[j]);
			j++;
		}
	}
	printf("%c\n", is_empty(&p) ? 'C' : 'E');
	return 0;
}
