#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;

unsigned int hash(int n) {
	return n % 262139;
}

int insert_hash_table(Node *hash_table, int e) {
	if (!hash_table) return 0;
	Node *new_node = malloc(sizeof(Node));
	if (!new_node) return 0;
	new_node->data = e;
	new_node->next = hash_table[hash(e)].next;
	hash_table[hash(e)].next = new_node;
	hash_table[hash(e)].data = 1;
	return 1;
}

Node* lookup_hash_table(Node *hash_table, int e) {
	Node *temp = hash_table[hash(e)].next;
	while (temp != NULL && temp->data != e)
		temp = temp->next;
	return temp;
}

int main() {
	int n, pi;
	scanf("%d", &n);
	Node *p = calloc(262139, sizeof(Node));
	for (int i = 0; i < n; i++) {
		scanf("%d", &pi);
		insert_hash_table(p, pi);
		
	} while (scanf("%d", &pi) != EOF) {
		if (p[hash(pi)].data == 0 || !lookup_hash_table(p, pi))
			printf("nao\n");
		else
			printf("sim\n");
	} free(p);
	return 0;
}
