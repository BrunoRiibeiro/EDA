#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct Queue {
	Item *v;
	int size, front, begin, end;
}Queue;

int create_queue(Queue *f, int s) {
	f->size = s;
	f->v = malloc(sizeof(Item) * s);
	if (f->v == NULL) return 0;
	f->front = 0;
	f->begin = -1;
	f->end = 0;
	return 1;
}

int is_empty(Queue *f) {
	return f->front == 0;
}

Item front(Queue *f) {
	return f->v[(f->begin+1) % f->size];
}

int enqueue(Queue *f, Item e) {
	if (f->end == f->begin) return 0;
	f->v[f->end++] = e;
	f->end = f->end % f->size;
	f->front++;
	return 1;
}

void dequeue(Queue *f) {
	f->front--;
	f->begin = (f->begin+1) % f->size;
}

int queueofone(Queue *f) {
	return f->front == 1;
}

int main() {
	int n, ind = 0;
	scanf("%d", &n);
	Queue cards, dcards;
	create_queue(&cards, n);
	create_queue(&dcards, n-1);
	for (int i = 1; i <= n; i++)
		enqueue(&cards, i);
	while (queueofone(&cards) != 1) {
		Item temp = front(&cards);
		dequeue(&cards);
		if (ind % 2 == 0)
			enqueue(&dcards, temp);
		else
			enqueue(&cards, temp);
		ind++;
	}
	printf("Cartas descartadas: %d", front(&dcards));
	for (int i = 1; i < n-1; i++)
		printf(", %d", dcards.v[i]);
	printf("\nCarta restante: %d\n", front(&cards));
	return 0;
}
