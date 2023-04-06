#include <stdio.h>

int main() {
	int n = 1, j = 0, beto_wins[100], alice_wins[100];

	while (n != 0) {
		scanf("%d", &n);
		
		int lst[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &lst[i]);
		}
		
		int b_win = 0, a_win = 0;
		for (int i = 0; i < n; i++) {
			if (lst[i] == 0) {
				a_win++;
			}
			if (lst[i] == 1) {
				b_win++;
			}
		}
		alice_wins[j] = a_win;
		beto_wins[j] = b_win;
		j++;
	}

	for (int i = 0; i < j; i++) {
			if (alice_wins[i] || beto_wins[i] != 0) { 
				printf("Alice ganhou %d e Beto ganhou %d\n", alice_wins[i], beto_wins[i]);
			}
	}	
	return 0;
}
