#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;
typedef struct Node {
	Item data;
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

int insert_first(Head *h, Item e) {
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) return 0;
	new_node->data = e;
	new_node->next = NULL;
	new_node->back = NULL;
	h->begin = new_node;
	h->end = new_node;
	return 1;
}

int toFront(Head *h, Item e) {
	if (h->begin == NULL) {
		insert_first(h, e);
		return 0;
	}
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) return 0;
	new_node->data = e;
	new_node->next = h->begin;
	h->begin->back = new_node;
	h->begin = new_node;
	new_node->back = NULL;
	return 1;
}

int push_back(Head *h, Item e) {
	if (h->begin == NULL) {
		insert_first(h, e);
		return 0;
	}
	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) return 0;
	new_node->data = e;
	new_node->next = NULL;
	new_node->back = h->end;
	h->end->next = new_node;
	h->end = new_node;
	return 1;
}

void front(Head *h) {
	if (h->begin == NULL) {
		printf("No job for Ada?\n");
		return;
	}
	Node *toremove = h->begin;
	if (h->begin == h->end)
		h->end = NULL;
	h->begin = h->begin->next;
	if (h->begin)
		h->begin->back = NULL;
	Item ret = toremove->data;
	free(toremove);
	printf("%d\n", ret);
}

void back(Head *h) {
	if (h->end == NULL) {
		printf("No job for Ada?\n");
		return;
	}
	Node *toremove = h->end;
	if (h->begin == h->end)
		h->begin = NULL;
	h->end = h->end->back;
	if (h->end)
		h->end->next = NULL;
	Item ret = toremove->data;
	free(toremove);
	printf("%d\n", ret);
}

int main() {
	Head h;
	create_queue(&h);
	long int q; int isre = 0;
	scanf("%ld", &q);
	Item n;
	for (long int i = 0; i < q; i++) {
		char str[10];
		scanf("%s", str);
		if (strcmp(str, "reverse") == 0) {
			if (isre)
				isre = 0;
			else
				isre = 1;
		} else if (strcmp(str, "front") == 0) {
			if (isre)
				back(&h);
			else
				front(&h);
		} else if (strcmp(str, "back") == 0) {
			if (isre)
				front(&h);
			else
				back(&h);
		} else if (strcmp(str, "toFront") == 0) {
			scanf("%d", &n);
			if (isre)
				push_back(&h, n);
			else
				toFront(&h, n);
		} else if (strcmp(str, "push_back") == 0) {
			scanf("%d", &n);
			if (isre)
				toFront(&h, n);
			else
				push_back(&h, n);
		}
	}
	return 0;
}
