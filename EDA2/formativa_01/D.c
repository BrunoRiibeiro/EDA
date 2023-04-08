#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;

Node *busca(Node *h, int x) {
	Node *aux = h->next;
	while (aux) {
		if (aux->data == x) return aux;
		aux = aux->next;
	}
}

Node *busca_rec(Node *h, int x) {
	if (!h->next) return NULL;
	Node *aux = h->next;
	if (aux->data == x) return aux;
	busca_rec(aux, x);
}
