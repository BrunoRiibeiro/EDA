#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;

void imprime(Node *h) {
	Node *aux = h->next;
	while (aux) {
		printf("%d -> ", aux->data);
		aux = aux->next;
	}
	printf("NULL\n");
}

void imprime_rec(Node *h) {
	Node *aux = h->next;
	if (!aux) {
		printf("NULL\n"); return;
	}
	printf("%d -> ", aux->data);
	imprime_rec(aux);
}
