#include <stdio.h>

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int knapsack(int capacity, int weights[], int profits[], int n) {
    int T[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                T[i][j] = 0;
            else if (weights[i - 1] <= j)
                T[i][j] = max(profits[i - 1] + T[i - 1][j - weights[i - 1]], T[i - 1][j]);
            else
                T[i][j] = T[i - 1][j];
        }
    }

    printf("\nKnapsack Table:\n");
    printf("i j  ");
    for (int j = 0; j <= capacity; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i <= n; i++) {
        printf("%2d   ", i);
        for (int j = 0; j <= capacity; j++) {
            printf("%2d ", T[i][j]);
        }
        printf("\n");
    }

    int x[n];
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    int remaining_capacity = capacity;
    for (int i = n; i > 0 && remaining_capacity > 0; i--) {
        if (T[i][remaining_capacity] != T[i - 1][remaining_capacity]) {
            x[i - 1] = 1;
            remaining_capacity -= weights[i - 1];
        }
    }

    printf("\nOptimal solution: (");
    for (int i = 0; i < n; i++) {
        printf("x%d", i + 1);
        if (i < n - 1) printf(", ");
    }
    printf(") --> (");
    for (int i = 0; i < n; i++) {
        printf("%d", x[i]);
        if (i < n - 1) printf(", ");
    }
    printf(")\n");

    return T[n][capacity];
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profits[n], weights[n];

    printf("Enter profits of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("\nMaximum profit: %d\n", knapsack(capacity, weights, profits, n));

    return 0;
}

