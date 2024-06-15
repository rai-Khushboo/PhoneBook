#include <iostream>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

const int MAX_CONTACTS = 100; // Maximum number of contacts
Contact phonebook[MAX_CONTACTS]; // Array to store contacts
int hashTable[MAX_CONTACTS] = {0}; // Hash table to track filled indices in phonebook

// Hash function to convert contact name to an index
int hashFunction(const string& name) {
    int sum = 0;
    for (char c : name) {
        sum += c;
    }
    return sum % MAX_CONTACTS;
}

// Function to add a new contact to the phonebook
void addContact(const string& name, const string& phoneNumber) {
    int index = hashFunction(name);
    while (hashTable[index] != 0) {
        index = (index + 1) % MAX_CONTACTS; // Linear probing to handle collisions
    }
    phonebook[index].name = name;
    phonebook[index].phoneNumber = phoneNumber;
    hashTable[index] = 1;
    cout << "Contact added successfully.\n";
}

// Function to search for a contact in the phonebook
void searchContact(const string& name) {
    int index = hashFunction(name);
    while (phonebook[index].name != "" && phonebook[index].name != name) {
        index = (index + 1) % MAX_CONTACTS; // Linear probing
    }
    if (phonebook[index].name == name) {
        cout << "Contact found:\n";
        cout << "Name: " << phonebook[index].name << "\n";
        cout << "Phone Number: " << phonebook[index].phoneNumber << "\n";
    } else {
        cout << "Contact not found.\n";
    }
}

// Function to display all contacts in alphabetical order
void displayContacts() {
    Contact sortedPhonebook[MAX_CONTACTS];
    int filledIndices = 0;
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (hashTable[i] == 1) {
            sortedPhonebook[filledIndices++] = phonebook[i];
        }
    }
    // Bubble sort
    for (int i = 0; i < filledIndices - 1; i++) {
        for (int j = 0; j < filledIndices - i - 1; j++) {
            if (sortedPhonebook[j].name > sortedPhonebook[j + 1].name) {
                swap(sortedPhonebook[j], sortedPhonebook[j + 1]);
            }
        }
    }
    cout << "Contacts:\n";
    for (int i = 0; i < filledIndices; i++) {
        cout << "Name: " << sortedPhonebook[i].name << "\n";
        cout << "Phone Number: " << sortedPhonebook[i].phoneNumber << "\n";
    }
}

int main() {
    char choice;
    do {
        cout << "\nPhonebook Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Display All Contacts\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Consume newline
        switch (choice) {
            case '1': {
                string name, phoneNumber;
                cout << "Enter contact name: ";
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                addContact(name, phoneNumber);
                break;
            }
            case '2': {
                string name;
                cout << "Enter contact name to search: ";
                getline(cin, name);
                searchContact(name);
                break;
            }
            case '3':
                displayContacts();
                break;
            case '4':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != '4');

    return 0;
}
