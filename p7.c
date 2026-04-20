#include <stdio.h>

int main() {
    FILE *fp;
    int choice;
    char text[200];

    while (1) {
        printf("\n1. Write\n2. Read\n3. Append\n4. Clear File\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        if (choice == 1) {
            fp = fopen("myfile.txt", "w");
            if (fp == NULL) {
                printf("File error!\n");
                continue;
            }
            printf("Enter text:\n");
            fgets(text, 200, stdin);
            fprintf(fp, "%s", text);
            fclose(fp);
            printf("Done!\n");
        }

        else if (choice == 2) {
            fp = fopen("myfile.txt", "r");
            if (fp == NULL) {
                printf("File not found!\n");
                continue;
            }
            printf("Content:\n");
            while (fgets(text, 200, fp) != NULL) {
                printf("%s", text);
            }
            fclose(fp);
        }

        else if (choice == 3) {
            fp = fopen("myfile.txt", "a");
            if (fp == NULL) {
                printf("File error!\n");
                continue;
            }
            printf("Enter text to add:\n");
            fgets(text, 200, stdin);
            fprintf(fp, "%s", text);
            fclose(fp);
            printf("Added!\n");
        }

        else if (choice == 4) {
            fp = fopen("myfile.txt", "w");
            if (fp != NULL) {
                fclose(fp);
                printf("File cleared!\n");
            }
        }

        else if (choice == 5) {
            break;
        }

        else {
            printf("Wrong choice!\n");
        }
    }

    return 0;
}