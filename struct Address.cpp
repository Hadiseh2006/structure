#include <iostream>

using namespace std;

struct Address {
    string city;
    string street;
};

struct Person {
    string name;
    int age;
    Address address;
};

int main() {
    // ایجاد یک شیء از نوع Person با استفاده از مقداردهی اولیه
    Person person = {"Ali", 30, {"Tehran", "Valiasr Street"}};

    cout << "Name: " << person.name << endl;
    cout << "Age: " << person.age << endl;
    cout << "City: " << person.address.city << endl;
    cout << "Street: " << person.address.street << endl;

    return 0;
}
