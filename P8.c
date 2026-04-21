#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp, *fodd, *feven;
    int num;

    // Open input file
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file 'data.txt'\n");
        return 1;
    }

    // Open output files
    fodd = fopen("odd.txt", "w");
    feven = fopen("even.txt", "w");

    if (fodd == NULL || feven == NULL) {
        printf("Error: Cannot create output files\n");
        return 1;
    }

    // Read numbers and separate
    while (fscanf(fp, "%d", &num) != EOF) {
        if (num % 2 == 0)
            fprintf(feven, "%d ", num);
        else
            fprintf(fodd, "%d ", num);
    }

    fclose(fp);
    fclose(fodd);
    fclose(feven);

    // Display odd numbers
    fodd = fopen("odd.txt", "r");
    printf("\nOdd Numbers:\n");
    while (fscanf(fodd, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    fclose(fodd);

    // Display even numbers
    feven = fopen("even.txt", "r");
    printf("\nEven Numbers:\n");
    while (fscanf(feven, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    fclose(feven);

    return 0;
}