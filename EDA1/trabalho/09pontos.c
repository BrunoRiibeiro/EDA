#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;
typedef struct Node {
	Item *data;
	struct Node *back, *next;
}Node;
typedef struct Head {
	Node *begin, *end;
}Head;

int create_queue(Head *h) {
	h->begin = NULL;
	h->end = NULL;
	return 1;
}

int first_enqueue(Head *h, Item *e) {
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) return 0;
	new_node->data = e;
	new_node->next = NULL;
	new_node->back = NULL;
	h->begin = new_node;
	h->end = new_node;
	return 1;
}

int enqueue(Head *h, Item *e) {
	if (h->begin == NULL) {
		first_enqueue(h, e);
		return 0;
	}
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) return 0;
	new_node->data = e;
	new_node->back = NULL;
	new_node->next = h->end;
	h->end->back = new_node;
	h->end = new_node;
	return 1;
}

Item* dequeue(Head *h) {
	Node *toremove = h->begin;
	if (h->end == h->begin)
		h->end = NULL;
	h->begin = h->begin->back;
	if (h->begin)
		h->begin->next = NULL;
	Item *ret = toremove->data;
	free(toremove);
	return ret;
}

Item* front(Head *h) {
	return h->begin->data;
}

void printlist(Head *h) {
	Node *aux = h->begin;
	while (aux) {
		printf("%s\n", aux->data);
		aux = aux->back;
	}
}

int main() {
	Head h, hf;
	create_queue(&h);
	while (1) {
		Item *c = malloc(sizeof(Item) * 27);
		if (scanf("%s", c) == EOF)
			break;
		enqueue(&h, c);
	}
	create_queue(&hf);
	Node *aux = h.begin;
	while (aux) {
		int last_index = strlen(aux->data) - 1;
		if (aux->back && aux->back->data[0] == aux->data[last_index]-32) {
			enqueue(&hf, dequeue(&h));
			enqueue(&h, dequeue(&h));
		}
		else {
			enqueue(&hf, dequeue(&h));
		}
		aux = h.begin;
	}
	printlist(&hf);
	return 0;
}
