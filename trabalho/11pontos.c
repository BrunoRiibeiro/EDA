#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int x, y;
}Item;

void main() {
    int n, m, tower_height = 0, h, acc = 0;
    scanf("%d %d", &n, &m);
    Item tower[n*m];
    char field[n][m], aux;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)  {
            scanf("%c", &aux);
            if  (aux == '\n') 
                scanf("%c", &aux);
            field[i][j] = aux;
            if  (aux == 't') 
                tower[tower_height++] = (Item){i, j};
        }
    }
    for (int i = 0; i < tower_height; i++) {
        scanf("%d", &h);
        for (int j = tower[i].x - h; j <= tower[i].x + h; j++)
            for (int k = tower[i].y - h; k <= tower[i].y + h; k++)
                if (j >= 0 && j < n && k >= 0 && k < m && field[j][k] == '#') {
                    acc++;
                    field[j][k] = '.';
                }
    }
    printf("%d\n", acc);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%c", field[i][j]);        
        printf("\n");
    }
}
