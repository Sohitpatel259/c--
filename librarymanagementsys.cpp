#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author)
        : id(id), title(title), author(author), isIssued(false) {}
};

class User {
public:
    int userId;
    string name;
    int borrowedBooks;
    static const int borrowLimit = 3;

    User(int userId, string name)
        : userId(userId), name(name), borrowedBooks(0) {}
};

class BorrowRecord {
public:
    int bookId;
    int userId;
    time_t dueDate;
    bool isReturned;

    BorrowRecord(int bookId, int userId, time_t dueDate)
        : bookId(bookId), userId(userId), dueDate(dueDate), isReturned(false) {}
};

class LibraryManagementSystem {
private:
    vector<Book> books;
    vector<User> users;
    vector<BorrowRecord> borrowRecords;

    void saveDataToFile() {
        ofstream outFile("library_data.txt");
        for (const auto& book : books) {
            outFile << "B," << book.id << "," << book.title << "," << book.author << "," << book.isIssued << "\n";
        }
        for (const auto& user : users) {
            outFile << "U," << user.userId << "," << user.name << "," << user.borrowedBooks << "\n";
        }
        outFile.close();
    }

    void loadDataFromFile() {
        ifstream inFile("library_data.txt");
        if (!inFile) {
            cout << "No previous data found. Starting fresh.\n";
            return;
        }
        string line;
        while (getline(inFile, line)) {
            if (line[0] == 'B') {
                int id, isIssued;
                string title, author;
                size_t pos = 2;
                id = stoi(line.substr(pos, line.find(',', pos) - pos));
                pos = line.find(',', pos) + 1;
                title = line.substr(pos, line.find(',', pos) - pos);
                pos = line.find(',', pos) + 1;
                author = line.substr(pos, line.find(',', pos) - pos);
                pos = line.find(',', pos) + 1;
                isIssued = stoi(line.substr(pos));

                Book book(id, title, author);
                book.isIssued = isIssued;
                books.push_back(book);
            } else if (line[0] == 'U') {
                int userId, borrowedBooks;
                string name;
                size_t pos = 2;
                userId = stoi(line.substr(pos, line.find(',', pos) - pos));
                pos = line.find(',', pos) + 1;
                name = line.substr(pos, line.find(',', pos) - pos);
                pos = line.find(',', pos) + 1;
                borrowedBooks = stoi(line.substr(pos));

                User user(userId, name);
                user.borrowedBooks = borrowedBooks;
                users.push_back(user);
            }
        }
        inFile.close();
    }

    double calculateFine(time_t dueDate) {
        time_t currentTime = time(0);
        double fine = 0;
        if (currentTime > dueDate) {
            int daysLate = (currentTime - dueDate) / (60 * 60 * 24);
            fine = daysLate * 2.0;  // Assume $2 fine per day
        }
        return fine;
    }

public:
    LibraryManagementSystem() {
        loadDataFromFile();
    }

    ~LibraryManagementSystem() {
        saveDataToFile();
    }

    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void addUser(int userId, string name) {
        users.push_back(User(userId, name));
        cout << "User registered successfully!\n";
    }

    void viewBooks() {
        cout << "\n--- Library Books ---\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title
                 << ", Author: " << book.author
                 << ", Issued: " << (book.isIssued ? "Yes" : "No") << endl;
        }
    }

    void issueBook(int bookId, int userId) {
        for (auto& user : users) {
            if (user.userId == userId) {
                if (user.borrowedBooks >= User::borrowLimit) {
                    cout << "User has reached the borrowing limit.\n";
                    return;
                }
                for (auto& book : books) {
                    if (book.id == bookId) {
                        if (book.isIssued) {
                            cout << "Book is already issued.\n";
                            return;
                        }
                        book.isIssued = true;
                        user.borrowedBooks++;

                        time_t dueDate = time(0) + (7 * 24 * 60 * 60);  // Due date 7 days from now
                        borrowRecords.push_back(BorrowRecord(bookId, userId, dueDate));

                        cout << "Book issued successfully! Due date in 7 days.\n";
                        return;
                    }
                }
            }
        }
        cout << "Book or User not found.\n";
    }

    void returnBook(int bookId, int userId) {
        for (auto& record : borrowRecords) {
            if (record.bookId == bookId && record.userId == userId && !record.isReturned) {
                record.isReturned = true;
                for (auto& user : users) {
                    if (user.userId == userId) {
                        user.borrowedBooks--;
                    }
                }
                for (auto& book : books) {
                    if (book.id == bookId) {
                        book.isIssued = false;
                    }
                }
                double fine = calculateFine(record.dueDate);
                if (fine > 0) {
                    cout << "Book returned late. Fine: $" << fine << endl;
                } else {
                    cout << "Book returned successfully.\n";
                }
                return;
            }
        }
        cout << "No matching borrow record found.\n";
    }
};

int main() {
    LibraryManagementSystem library;
    int choice, id, userId;
    string title, author, name;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Add User\n3. View Books\n4. Issue Book\n5. Return Book\n6. Exit\n";
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
                cout << "Enter User ID: ";
                cin >> userId;
                cin.ignore();
                cout << "Enter User Name: ";
                getline(cin, name);
                library.addUser(userId, name);
                break;
            case 3:
                library.viewBooks();
                break;
            case 4:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                cout << "Enter User ID: ";
                cin >> userId;
                library.issueBook(id, userId);
                break;
            case 5:
                cout << "Enter Book ID to return: ";
                cin >> id;
                cout << "Enter User ID: ";
                cin >> userId;
                library.returnBook(id, userId);
                break;
            case 6:
                cout << "Exiting system.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
