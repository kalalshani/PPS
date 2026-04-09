#include <stdio.h>
#include <string.h>

// ---------- ARRAY FUNCTIONS ----------

// Function for sorting array (Bubble Sort)
void sortArray(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted Array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function for searching element (Linear Search)
void searchArray(int arr[], int n, int key) {
    int i, found = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Element not found!\n");
    }
}

// ---------- STRING FUNCTIONS ----------

// String Concatenation
void concatStrings(char str1[], char str2[]) {
    strcat(str1, str2);
    printf("Concatenated String: %s\n", str1);
}

// String Comparison
void compareStrings(char str1[], char str2[]) {
    int result = strcmp(str1, str2);

    if(result == 0) {
        printf("Strings are equal.\n");
    }
    else if(result < 0) {
        printf("String1 is smaller than String2.\n");
    }
    else {
        printf("String1 is greater than String2.\n");
    }
}

// ---------- MAIN FUNCTION ----------

int main() {
    int choice, subChoice;

    do {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Array Operations\n");
        printf("2. String Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter number.\n");
            while(getchar() != '\n'); // clear buffer
            continue;
        }

        switch(choice) {

            case 1: {
                int n, arr[100], key, i;

                printf("Enter number of elements: ");
                scanf("%d", &n);

                if(n <= 0 || n > 100) {
                    printf("Invalid size!\n");
                    break;
                }

                printf("Enter elements:\n");
                for(i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }

                printf("\n--- Array Menu ---\n");
                printf("1. Sort Array\n");
                printf("2. Search Element\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                if(subChoice == 1) {
                    sortArray(arr, n);
                }
                else if(subChoice == 2) {
                    printf("Enter element to search: ");
                    scanf("%d", &key);
                    searchArray(arr, n, key);
                }
                else {
                    printf("Invalid choice!\n");
                }

                break;
            }

            case 2: {
                char str1[100], str2[100];

                printf("Enter first string: ");
                scanf(" %[^\n]", str1);

                printf("Enter second string: ");
                scanf(" %[^\n]", str2);

                printf("\n--- String Menu ---\n");
                printf("1. Concatenate Strings\n");
                printf("2. Compare Strings\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                if(subChoice == 1) {
                    concatStrings(str1, str2);
                }
                else if(subChoice == 2) {
                    compareStrings(str1, str2);
                }
                else {
                    printf("Invalid choice!\n");
                }

                break;
            }

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 3);

    return 0;
}
