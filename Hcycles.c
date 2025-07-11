#include <stdio.h>
#define MAX 10
int n, source, cycleCount = 0;
int G[MAX][MAX], path[MAX];
void NextValue(int k) {
    while (1) {
        path[k] = (path[k] + 1) % (n + 1);
        if (path[k] == 0)
            return;
        if (G[path[k - 1]][path[k]] != 0) {
            int j;
            for (j = 1; j < k; j++) {
                if (path[j] == path[k])
                    break;
            }
            if (j == k) {
                if ((k < n) || (k == n && G[path[n]][source] != 0))
                    return;
            }
        }
    }
}
void Hamiltonian(int k) {
    while (1) {
        NextValue(k);
        if (path[k] == 0)
            return;
        if (k == n) {
            cycleCount++;
            printf("Hamiltonian cycle %d: ", cycleCount);
            for (int i = 1; i <= n; i++)
                printf("%d ", path[i]);
            printf("%d\n", source);
        } else {
            Hamiltonian(k + 1);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &source);
    for (int i = 1; i <= n; i++)
        path[i] = 0;
    path[1] = source;
    Hamiltonian(2);
    if (cycleCount == 0)
        printf("No Hamiltonian cycles found.\n");
    return 0;
}

