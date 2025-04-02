#include "Contact.h"
#include <iostream>
using namespace std;

Contact::Contact() : gender(1), age(0) {}

void Contact::setName(const string& n) { name = n; }
string Contact::getName() const { return name; }

void Contact::setGender(int g) { gender = g; }
int Contact::getGender() const { return gender; }
string Contact::getGenderString() const { 
    return gender == 1 ? "Male" : "Female"; 
}

void Contact::setAge(int a) { age = a; }
int Contact::getAge() const { return age; }

void Contact::setPhone(const string& p) { phone = p; }
string Contact::getPhone() const { return phone; }

void Contact::setAddress(const string& a) { address = a; }
string Contact::getAddress() const { return address; }

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