#include <stdio.h>

typedef struct Item {
    int left;
    int right;
}Item;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int total = 0;
		Item boot[31];
		for (int i = 0; i < 31; i++) {
			boot[i].right = 0;
			boot[i].left = 0;
		} 
		for (int i = 0; i < n; i++) {
			int size;
			char side;
			scanf("%d %c", &size, &side);
			if (side == 'E')
				boot[size - 30].left++;
			else
				boot[size - 30].right++;
		}
		for (int i = 0; i < 31; i++) {
			if (boot[i].left == 0 || boot[i].right == 0) continue;
			else {
				if (boot[i].left >= boot[i].right)
					total += boot[i].right;
				else
					total += boot[i].left;
			}
		}
		printf("%d\n", total);
	}
	return 0;
}
