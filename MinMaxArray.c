#include <stdio.h>
void MinMax(int f, int r);
int a[50];
int l = 0;
int min, max;
int main() {
int op, k;
do {
printf("Choose the option:\n 1 for entering array element \n 2 for stopping the input values \n");
scanf("%d", &op);
switch (op) {
case 1:
	printf("Enter array element: ");
        scanf("%d", &k);
        a[l] = k;
        l++;
        break;
case 2:
	printf("Elements of array are: ");
        for (int m = 0; m < l; m++) {
        printf("%d ", a[m]);
        }
        printf("\n");
	if (l > 0) {
        min = max = a[0];
        MinMax(0, l - 1);
        printf("Minimum: %d, Maximum: %d\n", min, max);
        } else {
        printf("Enter the array elements\n");
        }
        break;
default:
	printf("Enter either 1 or 2\n");
}
} while (op != 2);
}
void MinMax(int f, int n) {
int mid, min1, max1;
if (f == n) {
min = max = a[f];
} else if (f == n - 1) {
if (a[f] < a[n]) {
min = a[f];
max = a[n];
} else {
min = a[n];
max = a[f];
}
} else {
mid = (f + n) / 2;
MinMax(f, mid);
min1 = min;
max1 = max;
MinMax(mid + 1, n);
if (max < max1) {
max = max1;
}
if (min > min1) {
min = min1;
}
}
}

