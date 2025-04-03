#include "AddressBook.h"
#include <iostream>
using namespace std;

const string DATA_FILE = "addressbook.dat";

void showMenu() {
    cout << "********************************" << endl;
    cout << "*****  Address Book System *****" << endl;
    cout << "********************************" << endl;
    cout << "*****  1. Add Contact      *****" << endl;
    cout << "*****  2. Show Contacts    *****" << endl;
    cout << "*****  3. Delete Contact   *****" << endl;
    cout << "*****  4. Search Contact   *****" << endl;
    cout << "*****  5. Modify Contact   *****" << endl;
    cout << "*****  6. Clear Contacts   *****" << endl;
    cout << "*****  0. Exit             *****" << endl;
    cout << "********************************" << endl;
    cout << "********* Version 3.0 **********" << endl;
    cout << "********************************" << endl;
}

int main() {
    AddressBook myAddressBook;
    
    // Đọc dữ liệu khi khởi động
    myAddressBook.loadFromFile(DATA_FILE);
    
    int selection;

    while (true) {
        showMenu();
        cout << "Enter your selection: ";
        cin >> selection;

        switch (selection) {
            case 1: myAddressBook.addContact(); break;
            case 2: myAddressBook.showContacts(); break;
            case 3: myAddressBook.deleteContact(); break;
            case 4: myAddressBook.searchContact(); break;
            case 5: myAddressBook.modifyContact(); break;
            case 6: myAddressBook.clearContacts(); break;
            case 0: 
                // Lưu dữ liệu trước khi thoát
                myAddressBook.saveToFile(DATA_FILE);
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid selection, please try again!" << endl;
                system("pause");
                system("cls");
        }
    }
}