#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  	int value, id, next;
}Item;

typedef struct Node {
  	Item data;
  	struct Node *next;
}Node;

typedef struct Head {
  	Node *begin;
}Head;

int create_list(Head *h) {
  	h->begin = NULL;
  	return 1;
}

int push(Head *h, Item e) {
  	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) return 0;
  	new_node->data = e;
  	new_node->next = h->begin;
  	h->begin = new_node;
	return 1;
}

void pull(Head *h) {
	printf("%d\n", h->begin->data.value);
	h->begin = h->begin->next;
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	Item item[n];
	Head h;
	create_list(&h);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &item[i].id, &item[i].value, &item[i].next);
		if (item[i].next == -1)
			push(&h, item[i]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (item[j].next == h.begin->data.id)
				push(&h, item[j]);
	for (int i = 0; i < n; i++)
		pull(&h);
	return 0;
}
