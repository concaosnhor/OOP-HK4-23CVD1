#include "AddressBook.h"
#include <iostream>
#include <cstdlib>
using namespace std;

AddressBook::AddressBook() : count(0) {}

int AddressBook::getCount() const { return count; }

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

void AddressBook::showContacts() const {
    if (count == 0) {
        cout << "No contacts available, please add some first!" << endl;
    } else {
        for (int i = 0; i < count; i++) {
            contacts[i].displayContact();
        }
    }
    system("pause");
    system("cls");
}

int AddressBook::findContact(const string& name) const {
    for (int i = 0; i < count; i++) {
        if (contacts[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

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