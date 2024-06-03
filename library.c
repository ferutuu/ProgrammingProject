#include <stdio.h>
#include <string.h>
#include "library.h"

Book library[MAX_BOOKS];
BorrowedBook borrowedBooks[MAX_BOOKS];

int num_borrowed_books = 0;
int num_books = 0;

void registration(){
    char name[20], surname[20], user[20];
    char choice;
    printf("Do you have an account? Y/N\n");
    scanf("%c",&choice);

    if(choice == 'N' || choice == 'n'){
        printf("Enter your name: ");
        scanf("%s",name);
        printf("Enter your surname: ");
        scanf("%s",surname);
        printf("Create a username: ");
        scanf("%s",user);
        printf("Hello, %s. Choose what you want to do.\n\n",user);
    }
    else if(choice == 'Y' || choice == 'y'){
        printf("Enter username: ");
        scanf("%s",user);
        printf("Welcome back, %s. Choose what you want to do.\n\n",user);
    }
    else {
        printf("Invalid input, please enter (Y)es or (N)o.\n");
            scanf("%c",&choice);
            registration();
        }

}

void add_book() {
    if (num_books < MAX_BOOKS) {
        Book newBook;

        printf("Title of the book: ");
        fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
        newBook.title[strcspn(newBook.title, "\n")] = 0;

        printf("Author of the book: ");
        fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
        newBook.author[strcspn(newBook.author, "\n")] = 0;

        newBook.available = 1;
        library[num_books] = newBook;
        num_books++;
        printf("Book added successfully\n");
    } else {
        printf("Library is full\n");
    }
}

void search_book(char *title) {
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            printf("Book found\n\n");
            printf("Title: %s\nAuthor: %s\n\n", library[i].title, library[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found\n");
    }
}

void borrow_book(char *title) {
    int index = -1;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Book not found\n");
        return;
    }
    if (library[index].available <= 0) {
        printf("Book %s is not available\n", title);
        return;
    }

    library[index].available--;
    strcpy(borrowedBooks[num_borrowed_books].title, title);
    num_borrowed_books++;
    save_library();
    printf("Book %s borrowed successfully\n", title);
}

void return_book(char *title) {
    int index = -1;
    for (int i = 0; i < num_borrowed_books; i++) {
        if (strcmp(borrowedBooks[i].title, title) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Book not found in borrowed list\n");
        return;
    }
    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0) {
            library[i].available++;
            break;
        }
    }
    for (int i = index; i < num_borrowed_books - 1; i++) {
        strcpy(borrowedBooks[i].title, borrowedBooks[i + 1].title);
    }
    num_borrowed_books--;
    printf("Book returned successfully\n");
}

void display_books() {
    if (num_books == 0) {
        printf("Library is empty\n");
    } else {
        printf("Books in the library:\n\n");
        for (int i = 0; i < num_books; i++) {
            printf("Title: %s\nAuthor: %s\n\n", library[i].title, library[i].author);
        }
    }
}

void save_library() {
    FILE *file = fopen("library.txt", "w");
    for (int i = 0; i < num_books; i++) {
        fprintf(file, "%s;%s\n", library[i].title, library[i].author);
    }

    fclose(file);
}

void load_library() {
    FILE *file = fopen("library.txt", "r");
    while (fscanf(file, "%[^;];%[^\n]\n", library[num_books].title, library[num_books].author) != EOF) {
        num_books++;
        if (num_books >= MAX_BOOKS) {
            printf("Maximum size reached\n");
            break;
        }
    }

    fclose(file);
}
