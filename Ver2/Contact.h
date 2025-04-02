#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;

class Contact {
private:
    string name;
    int gender;
    int age;
    string phone;
    string address;

public:
    Contact();
    
    void setName(const string& n);
    string getName() const;
    
    void setGender(int g);
    int getGender() const;
    string getGenderString() const;
    
    void setAge(int a);
    int getAge() const;
    
    void setPhone(const string& p);
    string getPhone() const;
    
    void setAddress(const string& a);
    string getAddress() const;
    
    void inputContact();
    void displayContact() const;
};

#endif