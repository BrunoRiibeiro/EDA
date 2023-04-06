#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct Queue {
	Item *v;
	int size, front, begin, end;
}Queue;

int create_queue(Queue *f, int s) {
	f->size = s;
	f->v = malloc(s * sizeof(Item));
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
	if (f->front >= f->size) return 0;
	f->v[f->end++] = e;
	f->end = f->end % f->size;
	f->front++;
	return 1;
}

void dequeue(Queue *f) {
	f->front--;
	f->begin = (f->begin+1) % f->size;
}

int main() {
	int p, r, ntest = 1;
	scanf("%d %d", &p, &r);
	Queue f;
	while (p !=0 || r != 0) {
		int xp;
		create_queue(&f, p);
		for (int i = 0; i < p; i++) {
			scanf("%d", &xp);
			enqueue(&f, xp);
		}
		int j, ai;
		for (int i = 0; i < r; i++) {
			scanf("%d %d", &p, &j);
			for(int k = 0; k < p; k++) {
				Item temp = front(&f);
				dequeue(&f);
				scanf("%d", &ai);
				if (ai == j)
				enqueue(&f, temp);
			}
		}
		printf("Teste %d\n", ntest++);
		printf("%d\n", front(&f));
		scanf("%d %d", &p, &r);
	}
	return 0;
}
