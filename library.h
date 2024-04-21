#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

extern Book library[MAX_BOOKS];
extern int num_books;

void addBook();
void searchBook(char *title);
void displayBooks();
void saveLibraryToFile();
void loadLibraryFromFile();

#endif
