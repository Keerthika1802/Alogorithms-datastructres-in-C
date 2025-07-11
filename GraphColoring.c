#include <stdio.h>
void graphcoloring(int k);
void nextvalue(int k);
int n, m, c = 0, sol = 0;
int g[20][20], x[20];
int main() {
    int i, j;
    printf("\nEnter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("\nEnter adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    printf("\nAll possible solutions are:\n");
    for (m = 1; m <= n; m++) {
        if (c == 1)
            break;
        graphcoloring(1);
    }
    printf("\nChromatic number is %d", m - 1);
    printf("\nTotal number of solutions is %d", sol);
    
    return 0;
}
void graphcoloring(int k) {
    int i;
    while (1) {
        nextvalue(k);
        if (x[k] == 0)
            return;
        if (k == n) {
            c = 1;
            printf("Solution %d: ", sol + 1);
            for (i = 1; i <= n; i++)
                printf("%d ", x[i]);
            sol++;
            printf("\n");
        } else {
            graphcoloring(k + 1);
        }
    }
}	

void nextvalue(int k) {
    int j;
    while (1) {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
           return;
        for (j = 1; j <= n; j++) {
            if (g[k][j] == 1 && x[k] == x[j])
                break;
        }
        if (j == (n + 1))
            return;
    }
}

