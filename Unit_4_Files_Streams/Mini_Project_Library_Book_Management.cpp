#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author;
    string category;
    bool available;

public:
    Book(string i, string t, string a, string c, bool av = true)
        : isbn(i), title(t), author(a),
          category(c), available(av) {}

    string getISBN() const {
        return isbn;
    }

    bool isAvailable() const {
        return available;
    }

    void issue() {
        if (available) {
            available = false;
            cout << "Book issued successfully." << endl;
        } else {
            cout << "Book is already issued." << endl;
        }
    }

    void returnBook() {
        available = true;
        cout << "Book returned successfully." << endl;
    }

    void display() const {
        cout << "ISBN: " << isbn
             << " | Title: " << title
             << " | Author: " << author
             << " | Category: " << category
             << " | Status: "
             << (available ? "Available" : "Issued")
             << endl;
    }

    string toFileString() const {
        return isbn + "|" + title + "|" + author + "|" +
               category + "|" + (available ? "1" : "0");
    }
};

void saveBooks(const vector<Book>& books) {
    ofstream file("library.txt");

    if (!file) {
        cerr << "Unable to open library.txt." << endl;
        return;
    }

    for (const auto& book : books) {
        file << book.toFileString() << '\n';
    }
}

void displayAvailabilityReport(const vector<Book>& books) {
    cout << "\n=== Library Availability Report ===" << endl;

    for (const auto& book : books) {
        book.display();
    }
}

int main() {
    vector<Book> books;

    books.emplace_back(
        "978001", "C++ Programming",
        "Bjarne", "Programming"
    );

    books.emplace_back(
        "978002", "Data Structures",
        "Mark Allen", "Computer Science"
    );

    books.emplace_back(
        "978003", "Artificial Intelligence",
        "Stuart Russell", "AI"
    );

    cout << "=== Library Book Management ===" << endl;

    cout << "\nInitial Books:" << endl;
    displayAvailabilityReport(books);

    cout << "\nIssuing Book 978001:" << endl;

    for (auto& book : books) {
        if (book.getISBN() == "978001") {
            book.issue();
        }
    }

    cout << "\nSearching for ISBN 978002:" << endl;

    for (const auto& book : books) {
        if (book.getISBN() == "978002") {
            book.display();
        }
    }

    cout << "\nReturning Book 978001:" << endl;

    for (auto& book : books) {
        if (book.getISBN() == "978001") {
            book.returnBook();
        }
    }

    displayAvailabilityReport(books);

    saveBooks(books);

    cout << "\nBook records saved to library.txt." << endl;

    return 0;
}