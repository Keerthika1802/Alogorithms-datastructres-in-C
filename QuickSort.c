#include <stdio.h>

void quick(int f, int l);
int partition(int f, int l);

int a[50]; 
int l = 0; 

int main() {
    int op, k;
    
    do {
        printf("Choose the option:\n 1 for entering array element \n 2 for stopping input and sorting \n");
        scanf("%d", &op);

        switch (op) {
            case 1:
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
                printf("Elements of array before sorting: ");
                for (int m = 0; m < l; m++) {
                    printf("%d ", a[m]);
                }
                printf("\n");

                quick(0, l - 1);

                printf("Sorted Array: ");
                for (int m = 0; m < l; m++) {
                    printf("%d ", a[m]);
                }
                printf("\n");
                break;

            default:
                printf("Enter either 1 or 2\n");
        }
    } while (op != 2);

    return 0;
}

void quick(int f, int l) {
    if (f < l) {
        int j = partition(f, l);
        quick(f, j - 1);
        quick(j + 1, l);
    }
}

int partition(int f, int l) {
    int i = f, j = l, temp;
    int pvt = a[f];

    while (i < j) {
        while (i < j && a[i] <= pvt) {
            i++;
        }
        while (a[j] > pvt) {
            j--;
        }
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    a[f] = a[j];
    a[j] = pvt;

    return j;
}

