#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
	char str[16];
}Item;

unsigned int hash(char *s) {
	unsigned int key = 0, i = 0;
	while (s[i] != '\0')
		key += s[i++] * i;
	return (19 * key) % 101;
}

int add(Item *table, char *s) {
	int h = hash(s);
	for (int i = 0; i < 20; i++) {
		int ind = (h + i*i + 23*i) % 101;
		if (strcmp(table[ind].str, s) == 0) return 0;
	}
	for (int i = 0; i < 20; i++) {
		int ind = (h + i*i + 23*i) % 101;
    	if (table[ind].str[0] == '\0') {
			strcpy(table[ind].str, s);
			return 1;
		}
	}
	return 0;
}

int delete(Item *hash_table, char *s) {
	int h = hash(s);
	for (int i = 0; i < 20; i++) {
		int ind = (h + i*i + 23*i) % 101;
		if (strcmp(hash_table[ind].str, s) == 0) {
			hash_table[ind].str[0] = '\0';
			return 1;
		}
	}
	return 0;
}

int main() {
	unsigned char t;
	scanf("%hhu", &t);
	Item *table = calloc(109, sizeof(Item));
	char buff[20], aux[16];
	for (char i = 0; i < t; i++) {
		int n, total = 0;
		scanf("%d", &n);
		for (int j = 0; j < 101; j++)
			table[j].str[0] = '\0';
		for (int j = 0; j < n; j++) {
			scanf("%s", buff);
			int a = 2;
			while (buff[a++] != '\0')
				aux[a-3] = buff[a+1];
			if (buff[0] == 'A') {
				if (add(table, aux))
					total++;
			} else if (delete(table, aux))
				total--;
		}
		printf("%d\n", total);
		for (int i = 0; i < 101; i++)
			if (table[i].str[0] != '\0')
				printf("%d:%s\n", i, table[i].str);
	}
	free(table);
	return 0;
}
