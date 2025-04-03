#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include <fstream>

#define MAX_CONTACTS 1000

class AddressBook {
private:
    Contact contacts[MAX_CONTACTS];
    int count;

public:
    AddressBook();
    
    int getCount() const;
    
    void addContact();
    void showContacts() const;
    int findContact(const string& name) const;
    void deleteContact();
    void searchContact() const;
    void modifyContact();
    void clearContacts();
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif