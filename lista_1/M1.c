#include <stdio.h>
#include <string.h>

char side, matrix[1005][14], sides[501];
int turns, branches, coef = 0, sides_pos[501];

void print_trunk() {
    printf("~~~~~~~~~~~\n");
    for (int i = 4 + coef; i >= coef; i--) {
        for (int j = 0; j < 11; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    printf("~~~~~~~~~~~\n");
}

void set_lumberjack() {
    if (side == 'D') {
        matrix[coef][8] = 'L';
        matrix[coef + 1][8] = 'L';
    }
    if (side == 'E') {
        matrix[coef][2] = 'L';
        matrix[coef + 1][2] = 'L';
    }
}

void check_branches() {
    int j;
    for (int i = 0; i < branches; i++) {
        j = sides_pos[i] - 1;
        if (sides[i] == 'D') {
            matrix[j][8] = '-';
            matrix[j][9] = '-';
            matrix[j][10] = '-';
        }
        if (sides[i] == 'E') {
            matrix[j][1] = '-';
            matrix[j][2] = '-';
            matrix[j][3] = '-';
        }
    }
}

void create_trunk() {
    int numLoop;
    for (int i = 0; i < turns + 5; i++) {
        for (int j = 0; j < 11; j++) {
            if (i < turns) {
                if (j == 4 || j == 5 || j == 6) {
                    matrix[i][j] = '|';
                } else {
                    matrix[i][j] = ' ';
                }
            } else {
                matrix[i][j] = ' ';
            }
        }
    }
}

int check_death() {
    if (side == 'E' && matrix[coef + 2][2] == '-' && matrix[coef][4] == '>') {
        return 1;
    }
    if (side == 'D' && matrix[coef + 2][8] == '-' && matrix[coef][6] == '<') {
        return 1;
    }
    return 0;
}

int hit() {
    if (check_death()) {
        printf("**morreu**\n");
        return 1;
    }
    if ((matrix[coef][4] == '>' && side == 'E') || (matrix[coef][6] == '<' && side == 'D')) {
        coef++;
        set_lumberjack();
        return 0;
    }
    if (matrix[coef][4] == '|' && side == 'E') {
        matrix[coef][4] = '>';
        return 0;
    }
    if (matrix[coef][6] == '|' && side == 'D') {
        matrix[coef][6] = '<';
        return 0;
    }
}

int swap_side() {
    if (side == 'D') {
        if (matrix[coef][2] == '-' || matrix[coef + 1][2] == '-') {
            printf("**beep**\n");
            return 1;
        }
        matrix[coef][2] = 'L';
        matrix[coef + 1][2] = 'L';
        matrix[coef][8] = ' ';
        matrix[coef + 1][8] = ' ';
        side = 'E';
        return 0;
    }
    if (side == 'E') {
        if (matrix[coef][8] == '-' || matrix[coef + 1][8] == '-') {
            printf("**beep**\n");
            return 1;
        }
        matrix[coef][2] = ' ';
        matrix[coef + 1][2] = ' ';
        matrix[coef][8] = 'L';
        matrix[coef + 1][8] = 'L';
        side = 'D';
        return 0;
    }
}

int main() {
    int help;
    char aux, command[2001];

    scanf("%d", &turns);
    scanf("%d", &branches);

    for (int i = 0; i < branches; i++) {
        scanf(" %c", &aux);
        scanf("%d", &sides_pos[i]);
        sides[i] = aux;
    }
    scanf(" %c", &side);
    scanf("%s", command);
    create_trunk();
    check_branches();
    set_lumberjack();
    print_trunk();
    for (int i = 0; i < strlen(command); i++) {
        if (command[i] == 'T') {
            if (swap_side()) {
                continue;
            } else {
                print_trunk();
            }
        }
        if (command[i] == 'B') {
            help = hit();
            if (help == 1) {
                break;
            }
            print_trunk();
        }
    }
    return 0;
}