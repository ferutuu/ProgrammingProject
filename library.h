#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int available;
} Book;

typedef struct {
    char title[MAX_TITLE_LENGTH];
} BorrowedBook;

extern Book library[MAX_BOOKS];
extern int num_books;

void registration();
void add_book();
void search_book(char *title);
void display_books();
void save_library();
void load_library();
void borrow_book(char *title);
void return_book(char *title);

#endif