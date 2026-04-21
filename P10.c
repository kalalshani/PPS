#include<stdio.h>

int main() {
    int n, i, sum = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("Invalid size!");
        return 1;
    }

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum = %d", sum);

    return 0;
}