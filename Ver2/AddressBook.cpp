#include "AddressBook.h"
#include <iostream>
#include <iomanip>  
#include <cstdlib>  
using namespace std;

// Constructor khởi tạo count = 0
AddressBook::AddressBook() : count(0) {}

// Trả về số lượng contact trong sổ địa chỉ
int AddressBook::getCount() const { return count; }

// Thêm một contact mới vào sổ địa chỉ
void AddressBook::addContact() {
    if (count == MAX_CONTACTS) {
        cout << "Address book is full, cannot add more contacts!" << endl;
        return;
    }
    
    contacts[count].inputContact();
    count++;
    cout << "Contact added successfully!" << endl;
    system("pause");
    system("cls");
}

// Hiển thị danh sách contact theo dạng bảng
void AddressBook::showContacts() const {
    if (count == 0) {
        cout << "No contacts available, please add some first!" << endl;
    } else {
        // In tiêu đề bảng
        cout << "----------------------------------------------------------------------------------------\n";
        cout << "| " << left << setw(3)  << "No" 
             << "| " << setw(20) << "Name" 
             << "| " << setw(10) << "Gender" 
             << "| " << setw(5)  << "Age" 
             << "| " << setw(15) << "Phone" 
             << "| " << setw(25) << "Address" << " |\n";
        cout << "----------------------------------------------------------------------------------------\n";

        // Duyệt qua danh sách contact và in ra màn hình theo định dạng bảng
        for (int i = 0; i < count; i++) {
            cout << "| " << left << setw(3)  << (i + 1)  
                 << "| " << setw(20) << contacts[i].getName() 
                 << "| " << setw(10) << contacts[i].getGenderString()
                 << "| " << setw(5)  << contacts[i].getAge()
                 << "| " << setw(15) << contacts[i].getPhone()
                 << "| " << setw(25) << contacts[i].getAddress() << " |\n";
        }

        cout << "----------------------------------------------------------------------------------------\n";
    }
    system("pause");
    system("cls");
}

// Tìm kiếm một contact theo tên, trả về chỉ mục nếu tìm thấy, -1 nếu không có
int AddressBook::findContact(const string& name) const {
    for (int i = 0; i < count; i++) {
        if (contacts[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

// Xóa một contact theo tên
void AddressBook::deleteContact() {
    string name;
    cout << "Enter the name of the contact to delete: ";
    cin.ignore();
    getline(cin, name);

    int index = findContact(name);
    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        count--;
        cout << "Contact deleted successfully!" << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
    system("pause");
    system("cls");
}

// Tìm và hiển thị thông tin một contact theo tên
void AddressBook::searchContact() const {
    string name;
    cout << "Enter the name of the contact to search: ";
    cin.ignore();
    getline(cin, name);

    int index = findContact(name);
    if (index != -1) {
        contacts[index].displayContact();
    } else {
        cout << "Contact not found!" << endl;
    }
    system("pause");
    system("cls");
}

// Chỉnh sửa thông tin một contact theo tên
void AddressBook::modifyContact() {
    string name;
    cout << "Enter the name of the contact to modify: ";
    cin.ignore();
    getline(cin, name);

    int index = findContact(name);
    if (index != -1) {
        contacts[index].inputContact();
        cout << "Contact modified successfully!" << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
    system("pause");
    system("cls");
}

// Xóa toàn bộ sổ địa chỉ
void AddressBook::clearContacts() {
    char choice;
    cout << "Are you sure you want to clear the address book? (Y/N): ";
    cin >> choice;

    if (toupper(choice) == 'Y') {
        count = 0;
        cout << "All contacts cleared!" << endl;
    } else {
        cout << "Operation cancelled!" << endl;
    }
    system("pause");
    system("cls");
}
