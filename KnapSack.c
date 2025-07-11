#include <stdio.h>
#include <stdlib.h>

struct Item {
int profit;
int weight;
double ratio;
};

int partition(struct Item arr[], int first, int last) {
double pivot = arr[last].ratio;
int i = first - 1;
for (int j = first; j < last; j++) {
if (arr[j].ratio > pivot) {
i++;
struct Item temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
struct Item temp = arr[i + 1];
arr[i + 1] = arr[last];
arr[last] = temp;
return (i + 1);
}

void quickSort(struct Item arr[], int first, int last) {
if (first < last) {
int pi = partition(arr, first, last);
quickSort(arr, first, pi - 1);
quickSort(arr, pi + 1, last);
}
}

double Knapsack(struct Item items[], int n, int m) {
if (n == 0) {
printf("No items.\n");
return 0.0;
}
int curWeight = 0;
double totalProfit = 0.0;
quickSort(items, 0, n - 1);
printf("Optimal Path: ");
for (int i = 0; i < n; i++) {
if (curWeight + items[i].weight <= m) {
curWeight += items[i].weight;
totalProfit += items[i].profit;
printf("Item%d: 1, ", i + 1);
} else {
int remCapacity = m - curWeight;
totalProfit += ((double)remCapacity / items[i].weight) * items[i].profit;
printf("Item%d: %.2f, ", i + 1, (double)remCapacity / items[i].weight);
break;
}
}
printf("\n");
return totalProfit;
}

int main() {
int n = 0, m = 0, choice;
struct Item items[50];
while (1) {
        printf("\n1. Add Items\n2. Print Profit and Optimal Path\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter knapsack capacity: ");
                scanf("%d", &m);
                n = 0;
                while (n < 50) {
                    printf("Enter profit and weight for item %d (enter -1 -1 to stop): ", n + 1);
                    int profit, weight;
                    scanf("%d %d", &profit, &weight);
                    if (profit == -1 && weight == -1) break;
                    items[n].profit = profit;
                    items[n].weight = weight;
                    items[n].ratio = (double)profit / weight;
                    n++;
                }
                break;
            case 2:
                if (n > 0) {
                    double maxProfit = Knapsack(items, n, m);
                    printf("Maximum Profit: %.2f\n", maxProfit);
                } else {
                    printf("No items entered.\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
return 0;
}

