#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int available; 
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook();
void checkOutBook();
void returnBook();
void viewCatalogue();

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Catalogue System:\n");
        printf("1. Add a Book\n");
        printf("2. Check Out a Book\n");
        printf("3. Return a Book\n");
        printf("4. View Catalogue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                checkOutBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                viewCatalogue();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("The library is full, cannot add more books.\n");
        return;
    }

    struct Book newBook;
    newBook.id = bookCount + 1;

    printf("Enter the book title: ");
    getchar(); 
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;  

    printf("Enter the book author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; 

    newBook.available = 1; 
    library[bookCount] = newBook;
    bookCount++;

    printf("Book added successfully with ID %d.\n", newBook.id);
}

void checkOutBook() {
    int bookId;
    printf("Enter the ID of the book to check out: ");
    scanf("%d", &bookId);

    if (bookId < 1 || bookId > bookCount) {
        printf("Invalid book ID!\n");
        return;
    }

    if (library[bookId - 1].available == 0) {
        printf("Sorry, the book is already checked out.\n");
    } else {
        library[bookId - 1].available = 0;
        printf("You have successfully checked out the book: %s\n", library[bookId - 1].title);
    }
}

void returnBook() {
    int bookId;
    printf("Enter the ID of the book to return: ");
    scanf("%d", &bookId);

    if (bookId < 1 || bookId > bookCount) {
        printf("Invalid book ID!\n");
        return;
    }

    if (library[bookId - 1].available == 1) {
        printf("The book is already available in the library.\n");
    } else {
        library[bookId - 1].available = 1;
        printf("You have successfully returned the book: %s\n", library[bookId - 1].title);
    }
}

void viewCatalogue() {
    if (bookCount == 0) {
        printf("The library has no books.\n");
        return;
    }

    printf("\nLibrary Catalogue:\n");
    printf("ID\tTitle\t\t\tAuthor\t\t\tAvailability\n");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%-20s\t%-20s\t%s\n", library[i].id, library[i].title, library[i].author, 
               library[i].available ? "Available" : "Checked out");
    }
}
