#include "AddressBook.h"
#include <iostream>
#include <iomanip>  
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
        cout << "----------------------------------------------------------------------------------------\n";
        cout << "| " << left << setw(3)  << "No" 
             << "| " << setw(20) << "Name" 
             << "| " << setw(10) << "Gender" 
             << "| " << setw(5)  << "Age" 
             << "| " << setw(15) << "Phone" 
             << "| " << setw(25) << "Address" << " |\n";
        cout << "----------------------------------------------------------------------------------------\n";

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

void AddressBook::saveToFile(const string& filename) const {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Cannot open file for writing!" << endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (int i = 0; i < count; i++) {
        contacts[i].serialize(outFile);
    }

    outFile.close();
    cout << "Contacts saved to file successfully!" << endl;
}

void AddressBook::loadFromFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Cannot open file for reading or file does not exist!" << endl;
        return;
    }

    inFile.read(reinterpret_cast<char*>(&count), sizeof(count));

    for (int i = 0; i < count; i++) {
        contacts[i].deserialize(inFile);
    }

    inFile.close();
    cout << "Contacts loaded from file successfully!" << endl;
}