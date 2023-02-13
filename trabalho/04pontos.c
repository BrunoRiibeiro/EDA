#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;
typedef struct Node {
	Item *data;
	struct Node *next;
}Node;
typedef struct Head {
	Node *begin;
}Head;

int create_stack(Head *h) {
	h->begin = NULL;
	return 1;
}

int push(Head *h, Item *e) {
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) return 0;
	new_node->data = e;
	new_node->next = h->begin;
	h->begin = new_node;
	return 1;
}

Item* pull(Head *h) {
	Node *toremove = h->begin;
	h->begin = h->begin->next;
	return toremove->data; 
}

int main() {
	Head h;
	create_stack(&h);
	char op[9];
	while (scanf("%s", op) != EOF) {
		if (strcmp(op, "desfazer") == 0) 
			printf("%s\n", h.begin == NULL ? "NULL" : pull(&h));
		else if (strcmp(op, "inserir") == 0) {
			char *str = malloc(sizeof(Item) * 101);
			scanf(" %[^\n]", str);
			push(&h, str);
		}
	}
	return 0;
}
