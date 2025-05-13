#include <iostream>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int year;
};

struct Library {
    Book* books; // آرایه‌ای از کتاب‌ها
    int n;    // تعداد کتاب‌ها
};void addBook(Library& lib, const Book& newBook) {
    Book* newBooks = new Book[lib.n + 1];
    for (int i = 0; i < lib.n; ++i) {
        newBooks[i] = lib.books[i];
    }
    newBooks[lib.n] = newBook;
    delete[] lib.books; // حذف آرایه قدیمی
    lib.books = newBooks;
    lib.n++;
}Book* findBookByTitle(const Library& lib, const string& title) {
    for (int i = 0; i < lib.n; ++i) {
        if (lib.books[i].title == title) {
            return &lib.books[i];
        }
    }
    return nullptr; // کتاب پیدا نشد
}void sortBooksByYear(Library& lib) {
    for (int i = 0; i < lib.n- 1; ++i) {
        for (int j = 0; j < lib.n - i - 1; ++j) {
            if (lib.books[j].year > lib.books[j + 1].year) {
                swap(lib.books[j], lib.books[j + 1]);
            }
        }
    }
}Library mergeLibraries(const Library& lib1, const Library& lib2) {
    Library newLib;
    newLib.n= lib1.n+ lib2.n;
    newLib.books = new Book[newLib.n];

    for (int i = 0; i < lib1.n; ++i) {
        newLib.books[i] = lib1.books[i];
    }
    for (int i = 0; i < lib2.n; ++i) {
        newLib.books[lib1.n+ i] = lib2.books[i];
    }

    return newLib;
}void deleteBookById(Library& lib, int id) {
    for (int i = 0; i < lib.n; ++i) {
        if (lib.books[i].id == id) {
            for (int j = i; j < lib.n - 1; ++j) {
                lib.books[j] = lib.books[j + 1];
            }
            lib.n--;
            Book* newBooks = new Book[lib.n];
            for (int k = 0; k < lib.n; ++k) {
                newBooks[k] = lib.books[k];
            }
            delete[] lib.books;
            lib.books = newBooks;
            break;
        }
    }
}void printBooksRecursive(const Library& lib, int index = 0) {
    if (index >= lib.n) return;
    cout << "ID: " << lib.books[index].id << ", Title: " << lib.books[index].title
         << ", Author: " << lib.books[index].author << ", Year: " << lib.books[index].year << endl;
    printBooksRecursive(lib, index + 1);
}Book createBook(int id, const string& title, const string& author, int year) {
    Book newBook;
    newBook.id = id;
    newBook.title = title;
    newBook.author = author;
    newBook.year = year;
    return newBook;
}int main() {
    Library lib;
    lib.books = nullptr;
    lib.n = 0;

    addBook(lib, createBook(1, "1984", "George Orwell", 1949));
    addBook(lib, createBook(2, "To Kill a Mockingbird", "Harper Lee", 1960));
    addBook(lib, createBook(3, "The Great Gatsby", "F. Scott Fitzgerald", 1925));

    cout << "Books after adding:" << endl;
    printBooksRecursive(lib);

    sortBooksByYear(lib);
    cout << "\nBooks after sorting by year:" << endl;
    printBooksRecursive(lib);

    deleteBookById(lib, 2);
    cout << "\nBooks after deleting ID 2:" << endl;
    printBooksRecursive(lib);

    return 0;
}
