#include<iostream>
#include<string>
using namespace std;

// Maximum number of contacts in the address book
#define Max 1000 

// Define a contact structure
struct Contacts
{
    string cName;        // Name
    int cGender = 1;     // Gender
    int cAge = 0;        // Age
    string cPhone;       // Phone number
    string cAdd;         // Address
};

// Define an address book structure
struct AddressBooks
{
    Contacts contactsArry[Max]; // Array to store contact information
    int aCount = 0;             // Number of contacts in the address book
};

// Display the main menu
void showMenu()
{
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
    cout << "*********** Version 1.0 ********" << endl;
    cout << "********************************" << endl;
}

// Add a contact
void AddContacts(AddressBooks* abs)
{
    // Check if the address book is full
    if (abs->aCount == Max)
    {
        cout << "Address book is full, cannot add more contacts!" << endl;
        return;
    }
    else
    {
        // Name
        string name;
        cout << "Enter name: " << endl;
        cin >> name;
        abs->contactsArry[abs->aCount].cName = name;

        // Gender
        int gender;
        cout << "Enter gender: " << endl;
        cout << "1 ---- Male " << endl;
        cout << "2 ---- Female " << endl;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->contactsArry[abs->aCount].cGender = gender;
                break;
            }
            cout << "Invalid input, please try again!" << endl;
        }

        // Age
        int age;
        cout << "Enter age: " << endl;
        cin >> age;
        abs->contactsArry[abs->aCount].cAge = age;

        // Phone number
        string phone;
        cout << "Enter phone number: " << endl;
        cin >> phone;
        abs->contactsArry[abs->aCount].cPhone = phone;

        // Address
        string add;
        cout << "Enter address: " << endl;
        cin >> add;
        abs->contactsArry[abs->aCount].cAdd = add;

        // Increase count
        abs->aCount += 1;
        cout << "Contact added successfully!" << endl;
        system("pause");
        system("cls");
    }
}

// Show all contacts
void ShowContacts(AddressBooks* abs)
{
    if (abs->aCount == 0)
    {
        cout << "No contacts available, please add some first!" << endl;
    }
    else
    {
        // Display all contacts
        for (int i = 0; i < abs->aCount; i++)
        {
            cout << "Name: " << abs->contactsArry[i].cName
                << " Gender: " << (abs->contactsArry[i].cGender != 2 ? "Male" : "Female")
                << " Age: " << abs->contactsArry[i].cAge
                << " Phone: " << abs->contactsArry[i].cPhone
                << " Address: " << abs->contactsArry[i].cAdd << endl;
        }
    }
    system("pause");
    system("cls");
}

// Check if a contact exists
int IsExit(AddressBooks* abs, string name)
{
    for (int i = 0; i < abs->aCount; i++)
    {
        if (abs->contactsArry[i].cName == name)
        {
            return i;
        }
    }
    return -1;
}

// Delete a contact
void DeleteContacts(AddressBooks* abs)
{
    string name;
    cout << "Enter the name of the contact to delete: " << endl;
    cin >> name;

    int index = IsExit(abs, name);

    if (index > -1)
    {
        for (int i = index; i < abs->aCount - 1; i++)
        {
            Contacts temp = abs->contactsArry[i];
            abs->contactsArry[i] = abs->contactsArry[i + 1];
            abs->contactsArry[i + 1] = temp;
        }
        abs->aCount--;
        cout << "Contact deleted successfully!" << endl;
    }
    else
    {
        cout << "Contact not found!" << endl;
    }
    system("pause");
    system("cls");
}

// Search for a contact
void GetContacts(AddressBooks* abs)
{
    string name;
    cout << "Enter the name of the contact to search: " << endl;
    cin >> name;

    int index = IsExit(abs, name);
    if (index > -1)
    {
        cout << "Name: " << abs->contactsArry[index].cName << endl;
        cout << "Gender: " << abs->contactsArry[index].cGender << endl;
        cout << "Age: " << abs->contactsArry[index].cAge << endl;
        cout << "Phone: " << abs->contactsArry[index].cPhone << endl;
        cout << "Address: " << abs->contactsArry[index].cAdd << endl;
    }
    else
    {
        cout << "Contact not found!" << endl;
    }
    system("pause");
    system("cls");
}

// Modify a contact
void ModifyContacts(AddressBooks* abs)
{
    string name;
    cout << "Enter the name of the contact to modify: " << endl;
    cin >> name;

    int index = IsExit(abs, name);
    if (index > -1)
    {
        cout << "Enter new name: " << endl;
        cin >> abs->contactsArry[index].cName;

        int gender;
        cout << "Enter new gender: " << endl;
        cout << "1 ---- Male " << endl;
        cout << "2 ---- Female " << endl;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->contactsArry[index].cGender = gender;
                break;
            }
            cout << "Invalid input, please try again!" << endl;
        }

        cout << "Enter new age: " << endl;
        cin >> abs->contactsArry[index].cAge;

        cout << "Enter new phone number: " << endl;
        cin >> abs->contactsArry[index].cPhone;

        cout << "Enter new address: " << endl;
        cin >> abs->contactsArry[index].cAdd;

        cout << "Contact modified successfully!" << endl;
    }
    else
    {
        cout << "Contact not found!" << endl;
    }
    system("pause");
    system("cls");
}

// Clear all contacts
void ClearContacts(AddressBooks* abs)
{
    string choice;
    cout << "Are you sure you want to clear the address book? (Y to confirm / N to cancel)" << endl;

    while (true)
    {
        cin >> choice;
        if (choice == "Y" || choice == "N")
        {
            break;
        }
        else
        {
            cout << "Invalid input, please try again!" << endl;
        }
    }

    if (choice == "Y")
    {
        abs->aCount = 0;
        cout << "All contacts cleared!" << endl;
    }
    else
    {
        cout << "Operation cancelled!" << endl;
    }
    system("pause");
    system("cls");
}

int main()
{
    int select = 0;
    AddressBooks abs;
    abs.aCount = 0;

    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1: AddContacts(&abs); break;
        case 2: ShowContacts(&abs); break;
        case 3: DeleteContacts(&abs); break;
        case 4: GetContacts(&abs); break;
        case 5: ModifyContacts(&abs); break;
        case 6: ClearContacts(&abs); break;
        case 0: cout << "Goodbye!" << endl; return 0;
        default: break;
        }
    }
}
