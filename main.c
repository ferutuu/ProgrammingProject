#include <stdio.h>
#include <string.h>
#include "library.h"

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];

    loadLibraryFromFile();

    do {
        printf("1. Add a book\n");
        printf("2. Search for a book\n");
        printf("3. Display all books\n");
        printf("4. Save library to file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character left in the input buffer

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                printf("Enter the title of the book to search: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // remove trailing newline
                searchBook(title);
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                saveLibraryToFile();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
