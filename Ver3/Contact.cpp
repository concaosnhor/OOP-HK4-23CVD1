#include "Contact.h"
#include <iostream>
using namespace std;

void Contact::inputContact() {
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Enter gender (1 for Male, 2 for Female): ";
    while (true) {
        cin >> gender;
        if (gender == 1 || gender == 2) break;
        cout << "Invalid input, please try again!" << endl;
    }
    
    cout << "Enter age: ";
    cin >> age;
    
    cout << "Enter phone number: ";
    cin >> phone;
    
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
}

void Contact::displayContact() const {
    cout << "Name: " << name
         << " Gender: " << getGenderString()
         << " Age: " << age
         << " Phone: " << phone
         << " Address: " << address << endl;
}