#include <stdio.h>

int BinSrchIter(int x, int n);
void sortArray();

int a[50]; 
int l = 0; 

int main() {
    int op, k, key, result;
    do {
        printf("Choose the option:\n 1 for entering array element \n 2 for searching an element \n 3 to exit\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                if (l >= 50) {
                    printf("Array is full\n");
                    break;
                }
                printf("Enter array element: ");
                scanf("%d", &k);
                a[l] = k;
                l++;
                break;

            case 2:
                if (l == 0) {
                    printf("Array is empty\n");
                    break;
                }
                printf("Enter the element to search: ");
                scanf("%d", &key);

                sortArray(); // Sort the array before performing binary search

                result = BinSrchIter(key, l);
                if (result != -1) {
                    printf("Element found at index %d\n", result);
                } else {
                    printf("Element not found in the array\n");
                }
                break;

            case 3:
                return 0;

            default:
                printf("Enter either 1, 2, or 3\n");
        }
    } while (1);
}

void sortArray() {
    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j < l - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int BinSrchIter(int x, int n) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x == a[mid])
            return mid;
        else if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

