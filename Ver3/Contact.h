#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <fstream>
using namespace std;

class Contact {
private:
    string name;
    int gender;
    int age;
    string phone;
    string address;

public:
    Contact() : gender(1), age(0) {}
    
    void setName(const string& n) { name = n; }
    string getName() const { return name; }
    
    void setGender(int g) { gender = g; }
    int getGender() const { return gender; }
    string getGenderString() const { 
        return gender == 1 ? "Male" : "Female"; 
    }
    
    void setAge(int a) { age = a; }
    int getAge() const { return age; }
    
    void setPhone(const string& p) { phone = p; }
    string getPhone() const { return phone; }
    
    void setAddress(const string& a) { address = a; }
    string getAddress() const { return address; }
    
    void inputContact();
    void displayContact() const;

    void serialize(ofstream& out) const {
        size_t len = name.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        out.write(name.c_str(), len);

        out.write(reinterpret_cast<const char*>(&gender), sizeof(gender));
        out.write(reinterpret_cast<const char*>(&age), sizeof(age));

        len = phone.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        out.write(phone.c_str(), len);

        len = address.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        out.write(address.c_str(), len);
    }

    void deserialize(ifstream& in) {
        size_t len;
        
        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        name.resize(len);
        in.read(&name[0], len);

        in.read(reinterpret_cast<char*>(&gender), sizeof(gender));
        in.read(reinterpret_cast<char*>(&age), sizeof(age));

        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        phone.resize(len);
        in.read(&phone[0], len);

        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        address.resize(len);
        in.read(&address[0], len);
    }
};

#endif