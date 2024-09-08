#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    bool isAvailable;

    Book(string t, string a) : title(t), author(a), isAvailable(true) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author) {
        books.push_back(Book(title, author));
        cout << "Book added: " << title << " by " << author << endl;
    }

    void displayBooks() {
        cout << "Available Books:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isAvailable) {
                cout << i + 1 << ". " << books[i].title << " by " << books[i].author << endl;
            }
        }
    }

    void borrowBook(int bookIndex) {
        if (bookIndex < 1 || bookIndex > books.size()) {
            cout << "Invalid book index.\n";
            return;
        }
        if (books[bookIndex - 1].isAvailable) {
            books[bookIndex - 1].isAvailable = false;
            cout << "You borrowed: " << books[bookIndex - 1].title << endl;
        } else {
            cout << "The book is not available.\n";
        }
    }

    void returnBook(int bookIndex) {
        if (bookIndex < 1 || bookIndex > books.size()) {
            cout << "Invalid book index.\n";
            return;
        }
        if (!books[bookIndex - 1].isAvailable) {
            books[bookIndex - 1].isAvailable = true;
            cout << "You returned: " << books[bookIndex - 1].title << endl;
        } else {
            cout << "This book was not borrowed.\n";
        }
    }
};

int main() {
    Library library;
    int choice, bookIndex;
    string title, author;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.displayBooks();
                cout << "Enter the book number to borrow: ";
                cin >> bookIndex;
                library.borrowBook(bookIndex);
                break;
            case 4:
                library.displayBooks();
                cout << "Enter the book number to return: ";
                cin >> bookIndex;
                library.returnBook(bookIndex);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
    