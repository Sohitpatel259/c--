#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;
    int issuedToUserId; 

    Book(int id, string title, string author)
        : id(id), title(title), author(author), isIssued(false), issuedToUserId(-1) {}
};

class LibraryManagementSystem {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void viewBooks() {
        cout << "\n--- Library Books ---\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id
                 << ", Title: " << book.title
                 << ", Author: " << book.author
                 << ", Issued: " << (book.isIssued ? "Yes" : "No");
            if (book.isIssued) {
                cout << ", Issued To User ID: " << book.issuedToUserId;
            }
            cout << endl;
        }
    }

    void issueBook(int bookId, int userId) {
        for (auto& book : books) {
            if (book.id == bookId) {
                if (book.isIssued) {
                    cout << "Book is already issued to User ID: " << book.issuedToUserId << ".\n";
                } else {
                    book.isIssued = true;
                    book.issuedToUserId = userId;
                    cout << "Book issued successfully to User ID: " << userId << ".\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int bookId, int userId) {
        for (auto& book : books) {
            if (book.id == bookId) {
                if (book.isIssued && book.issuedToUserId == userId) {
                    book.isIssued = false;
                    book.issuedToUserId = -1;
                    cout << "Book returned successfully by User ID: " << userId << ".\n";
                } else if (book.isIssued) {
                    cout << "Book is not issued to User ID: " << userId << ".\n";
                } else {
                    cout << "Book was not issued.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    LibraryManagementSystem library;
    int choice, id, userId;
    string title, author;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. View Books\n3. Issue Book\n4. Return Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore(); 
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;
            case 2:
                library.viewBooks();
                break;
            case 3:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                cout << "Enter User ID: ";
                cin >> userId;
                library.issueBook(id, userId);
                break;
            case 4:
                cout << "Enter Book ID to return: ";
                cin >> id;
                cout << "Enter User ID: ";
                cin >> userId;
                library.returnBook(id, userId);
                break;
            case 5:
                cout << "Exiting system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
