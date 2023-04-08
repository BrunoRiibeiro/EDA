#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;

void insere_inicio(Node *h, int x) {
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) return;
	new_node->next = h->next;
	new_node->data = x;
	h->next = new_node;
}

void insere_antes(Node *h, int x, int y) {
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) return;
	Node *aux = h->next;
	while (aux) {
		if (aux->data == y) {
			new_node->next = aux->next;
			new_node->data = aux->data;
			aux->next = new_node;
			aux->data = x;
			return;
		} else if (aux->next == NULL) {
			new_node->data = x;
			new_node->next = NULL;
			aux->next = new_node;
			return;
		}
		aux = aux->next;
	}
}
