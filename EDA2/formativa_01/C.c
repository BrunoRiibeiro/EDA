#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;

int remove_depois(Node *n) {
	Node *toremove = n->next;
	if (toremove) {
		n->next = n->next->next; return 1;
	} else
		return 0;
}

void remove_elemento(Node *h, int x) {
	Node *aux = h;
	while (aux->next) {
		if (aux->next->data == x) {
			aux->next = aux->next->next; return;
		}
		aux = aux->next;
	}
}

void remove_todos_elementos(Node *h, int x) {
	Node *aux = h;
	while (aux->next) {
		if (aux->next->data == x)
			aux->next = aux->next->next;
		else if(aux->next)
			aux = aux->next;
	}
}
