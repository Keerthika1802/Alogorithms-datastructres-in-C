#include <stdio.h>
#include <stdlib.h>

void sort(int lengths[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lengths[j] > lengths[j + 1]) {
                int temp = lengths[j];
                lengths[j] = lengths[j + 1];
                lengths[j + 1] = temp;
            }
        }
    }
}

void Store(int n, int m, int lengths[]) {
    int tapes[50][50] = {0};
    int count[50] = {0};
    int retrieval_time[50] = {0};
    int total_retrieval_time = 0;
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        tapes[j][count[j]++] = lengths[i];
        printf("Append program %d to permutation for Tape %d\n", i + 1, j + 1);
        j = (j + 1) % m;
    }

    printf("\nStorage Order of Programs on Each Tape:\n");
    for (int i = 0; i < m; i++) {
        printf("Tape %d:", i + 1);
        int sum = 0, cumulative = 0;
        for (int k = 0; k < count[i]; k++) {
            printf(" %d", tapes[i][k]);
            cumulative += tapes[i][k];
            sum += cumulative;
        }
        retrieval_time[i] = sum;
        total_retrieval_time += sum;
        printf("\n");
    }

    printf("\nTotal Retrieval Time for Each Tape:\n");
    for (int i = 0; i < m; i++) {
        printf("Tape %d total retrieval time: %d\n", i + 1, retrieval_time[i]);
    }

    printf("Total Retrieval Time for All Tapes: %d\n", total_retrieval_time);
    
}

int main() {
    int n, m;
    printf("Enter the number of programs: ");
    scanf("%d", &n);
    printf("Enter the number of tapes: ");
    scanf("%d", &m);
    
    int lengths[50];
    printf("Enter lengths of programs: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &lengths[i]);
    }
    
    sort(lengths, n);
    Store(n, m, lengths);
    
    return 0;
}

