#include <stdio.h>

int main() {
	unsigned char plays[15], team = 65, team1, team2, j = 0;
	for (int i = 0; i < 8; i++) {
		scanf("%hhu %hhu", &team1, &team2);
		if (team1 > team2)
			plays[i] = team;
		else
			plays[i] = team + 1;
		team += 2;
	}
	for (int i = 8; i < 15; i++) {
		scanf("%hhu %hhu", &team1, &team2);
		if (team1 > team2)
			plays[i] = plays[j];
		else
			plays[i] = plays[j + 1];
		j += 2;
	}

	printf("%c\n", plays[14]);
	return 0;
}
