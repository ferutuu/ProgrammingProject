#include <stdio.h>
#include <string.h>
#include "library.h"

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];

    load_library();
    registration();

    do {
        printf("1. Donate a book\n");
        printf("2. Look for a book\n");
        printf("3. Display all books\n");
        printf("4. Borrow book\n");
        printf("5. Return book\n");
        printf("6. Save changes and exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                printf("Title of the book to search: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0;
                search_book(title);
                break;
            case 3:
                display_books();
                break;
            case 4:
                printf("Title of the book to borrow: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0';
                borrow_book(title);
                break;
            case 5:
                printf("Title of the book to return: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0';
                return_book(title);
                break;
            case 6:
                save_library();
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
