#include <stdio.h>
#include <stdlib.h>

void createFile() {
    char filename[100], ch;
    FILE *fp;

    printf("Enter filename to create: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }

    printf("Start typing your text (Press `~` on a new line to stop):\n");

    getchar(); // clear buffer
    while ((ch = getchar()) != '~') {
        fputc(ch, fp);
    }

    fclose(fp);
    printf("File saved successfully as %s\n", filename);
}

void readFile() {
    char filename[100], ch;
    FILE *fp;

    printf("Enter filename to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file! File not found.\n");
        return;
    }

    printf("\n--- File Content ---\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n--- End of File ---\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Simple Text Editor =====\n");
        printf("1. Create & Write File\n");
        printf("2. Open & Read File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(); break;
            case 2: readFile(); break;
            case 3: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
