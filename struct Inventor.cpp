#include <iostream>
#include <cstring> // برای توابع کار با رشته‌ها
using namespace std;

// ساختار برای ذخیره اطلاعات یک مخترع
struct Inventor {
    char name[50];
    char invention[50];
    int year;
    bool isAlive;
    
    void display() {
        cout << "Inventor: " << name 
             << "\nInvention: " << invention
             << "\nYear: " << year
             << "\nStatus: " << (isAlive ? "Alive" : "Deceased")
             << "\n----------------------\n";
    }
    
    void updateStatus(bool currentStatus) {
        isAlive = currentStatus;
        cout << "Status updated for " << name << endl;
    }
};

// ساختار برای مدیریت یک اختراع
struct Invention {
    char name[50];
    Inventor creator;
    int patents;
    
    void showDetails() {
        cout << "\n=== Invention Details ==="
             << "\nName: " << name
             << "\nPatents: " << patents
             << "\nCreator Info:";
        creator.display();
    }
    
    void addPatent() {
        patents++;
        cout << "Patent added to " << name << " (Total: " << patents << ")\n";
    }
};

int main() {
    // ایجاد یک مخترع
    Inventor tesla;
    strcpy(tesla.name, "Nikola Tesla");
    strcpy(tesla.invention, "AC Electricity");
    tesla.year = 1887;
    tesla.isAlive = false;
    
    // ایجاد یک اختراع
    Invention acPower;
    strcpy(acPower.name, "AC Power System");
    acPower.creator = tesla;
    acPower.patents = 12;
    
    // نمایش اطلاعات
    acPower.showDetails();
    
    // اضافه کردن یک پتنت جدید
    acPower.addPatent();
    
    // ایجاد مخترع زنده
    Inventor currentInventor;
    strcpy(currentInventor.name, "Elon Musk");
    strcpy(currentInventor.invention, "Electric Cars");
    currentInventor.year = 2003;
    currentInventor.isAlive = true;
    
    currentInventor.display();
    currentInventor.updateStatus(true); // به روزرسانی وضعیت
    
    return 0;
}
