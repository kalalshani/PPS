#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100];
    long int pos;
    char ch;

    // Ask user for file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open file in read mode
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: File not found!\n");
        return 1;
    }

    // Move pointer to end of file
    fseek(fp, 0, SEEK_END);

    // Get current position (last character position)
    pos = ftell(fp);

    printf("\nFile content in reverse order:\n");

    // Read file in reverse
    while (pos) {
        pos--;