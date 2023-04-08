#include <stdio.h>
#define less(A,B) (A < B)

typedef struct Node {
	int data;
	struct Node *next;
}Node;

void mescla_listas(Node *l1, Node *l2, Node *l3) {
	Node *end = l3;
	l1 = l1->next; l2 = l2->next;
	while (l1 && l2) {
		if (less(l1->data, l2->data)) {
			end->next = l1;
			end = end->next;
			l1 = l1->next;
			end->next = NULL;
		} else {
			end->next = l2;
			end = end->next;
			l2 = l2->next;
			end->next = NULL;
		}
	}
	if (l1) end->next = l1;
	else end->next = l2;
}
