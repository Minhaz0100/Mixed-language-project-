#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    bool isBorrowed;

public:
    Book(string t, string a) : title(t), author(a), isBorrowed(false) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool getBorrowStatus() const {
        return isBorrowed;
    }

    void borrowBook() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << "You have borrowed \"" << title << "\"." << endl;
        } else {
            cout << "This book is already borrowed." << endl;
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << "You have returned \"" << title << "\"." << endl;
        } else {
            cout << "This book was not borrowed." << endl;
        }
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book \"" << book.getTitle() << "\" by " << book.getAuthor() << " added to the library." << endl;
    }

    void viewBooks() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }
        cout << "Available books:" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() 
                 << ", Status: " << (book.getBorrowStatus() ? "Borrowed" : "Available") << endl;
        }
    }

    void borrowBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.borrowBook();
                return;
            }
        }
        cout << "Book \"" << title << "\" not found in the library." << endl;
    }

    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.returnBook();
                return;
            }
        }
        cout << "Book \"" << title << "\" not found in the library." << endl;
    }
};

void displayMenu() {
    cout << "\nLibrary Management System" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. View Books" << endl;
    cout << "3. Borrow Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;
    string title, author;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                library.addBook(Book(title, author));
                break;

            case 2:
                library.viewBooks();
                break;

            case 3:
                cout << "Enter the title of the book to borrow: ";
                cin.ignore();
                getline(cin, title);
                library.borrowBook(title);
                break;

            case 4:
                cout << "Enter the title of the book to return: ";
                cin.ignore();
                getline(cin, title);
                library.returnBook(title);
                break;

            case 5:
                cout << "Exiting the system." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
