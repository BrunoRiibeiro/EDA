#include <stdio.h>
#include <stdlib.h>

typedef char Item;
typedef struct Stack {
	Item *v;
	int size, top;
}Stack;

int create_stack(Stack *p, int s) {
	p->size = s;
	p->v = malloc(s * sizeof(Item));
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

int bem_formada(char *v) {
	int i = 0;
	while (v[i] != '\0')
		i++;
	Stack p;
	create_stack(&p, i);
	i = 0;
	while (v[i] != '\0') {
		if (v[i] == '(' || v[i] == '[' || v[i] == '{') {
			push(&p, v[i]);
			i++;
		}
		else if (v[i] == ')') {
			if (top(&p) == '(') {
				pull(&p);
				i++;
			} else 
				return 0;
		} else if (v[i] == ']') {
			if (top(&p) == '[') {
				pull(&p);
				i++;
			} else 
				return 0;
		} else if (v[i] == '}') {
			if (top(&p) == '{') {
				pull(&p);
				i++;
			} else 
				return 0;
		}
	}
	if (is_empty(&p))
		return 1;
	return 0;
}

int main() {
	int t;
	char s[100001];
	scanf("%d",&t);
	for (int i = 0; i < t; i++) {
		scanf("%s", s);
		printf("%c\n", bem_formada(s) == 1 ? 'S' : 'N');
	}
	return 0;
}
