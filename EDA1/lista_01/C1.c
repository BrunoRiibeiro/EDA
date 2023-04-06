#include <stdio.h>

int main() {
    int n = 1, index = 0, index1[100], j[100], z[100], dif[100][100];

    while (n != 0) {
        index1[index] = 0;
        scanf("%d", &n);
     
		for (int i = 0; i < n; i++) {
            int jj = 0, zz = 0;
            scanf("%d%d", &jj, &zz);
            j[i] = jj;
            z[i] = zz;
            if (i == 0) {
                dif[index][i] = j[i] - z[i];
            } else {
                dif[index][i] = dif[index][i - 1] + j[i] - z[i];
            }
            index1[index]++;
        }
        if (n != 0) {
            index++;
        }
    }

    for (int i = 1; i <= index; i++) {
        printf("Teste %d\n", i);
        for (int j = 0; j < index1[i - 1]; j++) {
            printf("%d\n", dif[i - 1][j]);
        }
    }
    return 0;
}
