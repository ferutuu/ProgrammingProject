#include <stdio.h>
#include <string.h>
#include "library.h"

Book library[MAX_BOOKS];
int num_books = 0;

void addBook() {
    if (num_books < MAX_BOOKS) {
        Book newBook;
        printf("Enter the title of the book: ");
        fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
        newBook.title[strcspn(newBook.title, "\n")] = 0; // remove trailing newline
        printf("Enter the author of the book: ");
        fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
        newBook.author[strcspn(newBook.author, "\n")] = 0; // remove trailing newline

        library[num_books] = newBook;
        num_books++;

        printf("Book added successfully!\n");
    } else {
        printf("Library is full!\n");
    }
}

void searchBook(char *title) {
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            printf("Book found!\n");
            printf("Title: %s\nAuthor: %s\n", library[i].title, library[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found!\n");
    }
}

void displayBooks() {
    if (num_books == 0) {
        printf("Library is empty!\n");
    } else {
        printf("Books in the library:\n");
        for (int i = 0; i < num_books; i++) {
            printf("Title: %s\nAuthor: %s\n\n", library[i].title, library[i].author);
        }
    }
}

void saveLibraryToFile() {
    FILE *file = fopen("library.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < num_books; i++) {
        fprintf(file, "%s;%s\n", library[i].title, library[i].author);
    }

    fclose(file);
    printf("Library saved to file!\n");
}

void loadLibraryFromFile() {
    FILE *file = fopen("library.txt", "r");
    if (file == NULL) {
        printf("No library file found. Starting with an empty library.\n");
        return;
    }

    while (fscanf(file, "%[^;];%[^\n]\n", library[num_books].title, library[num_books].author) != EOF) {
        num_books++;
        if (num_books >= MAX_BOOKS) {
            printf("Max library size reached. Some books may not have been loaded.\n");
            break;
        }
    }

    fclose(file);
    printf("Library loaded from file!\n");
}