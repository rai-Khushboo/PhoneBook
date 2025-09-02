#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

const int MAX_CONTACTS = 100;
Contact phonebook[MAX_CONTACTS];
int hashTable[MAX_CONTACTS] = {0};

int hashFunction(const string& name) {
    int sum = 0;
    for (char c : name) {
        sum += tolower(c); 
    }
    return sum % MAX_CONTACTS;
}

// phone number (basic digits only)
bool isValidPhoneNumber(const string& number) {
    if (number.length() < 7 || number.length() > 15) return false;
    for (char c : number) {
        if (!isdigit(c) && c != '+' && c != '-') return false;
    }
    return true;
}

// Add Contact
void addContact(const string& name, const string& phoneNumber) {
    if (!isValidPhoneNumber(phoneNumber)) {
        cout << "Invalid phone number format.\n";
        return;
    }

    int index = hashFunction(name);
    int startIndex = index;
    do {
        if (hashTable[index] == 0 || phonebook[index].name == name) {
            phonebook[index].name = name;
            phonebook[index].phoneNumber = phoneNumber;
            hashTable[index] = 1;
            cout << "Contact added/updated successfully.\n";
            return;
        }
        index = (index + 1) % MAX_CONTACTS;
    } while (index != startIndex);

    cout << "Phonebook is full.\n";
}

// Search by name
int findContactIndex(const string& name) {
    int index = hashFunction(name);
    int startIndex = index;
    do {
        if (hashTable[index] == 1 && phonebook[index].name == name) {
            return index;
        }
        index = (index + 1) % MAX_CONTACTS;
    } while (index != startIndex);
    return -1;
}

void searchContact(const string& name) {
    int index = findContactIndex(name);
    if (index != -1) {
        cout << "Contact found:\n";
        cout << "Name: " << phonebook[index].name << "\n";
        cout << "Phone Number: " << phonebook[index].phoneNumber << "\n";
    } else {
        cout << "Contact not found.\n";
    }
}

// Update contact
void updateContact(const string& name) {
    int index = findContactIndex(name);
    if (index != -1) {
        cout << "Enter new phone number: ";
        string newNumber;
        getline(cin, newNumber);
        if (isValidPhoneNumber(newNumber)) {
            phonebook[index].phoneNumber = newNumber;
            cout << "Contact updated.\n";
        } else {
            cout << "Invalid number format.\n";
        }
    } else {
        cout << "Contact not found.\n";
    }
}

// Delete contact
void deleteContact(const string& name) {
    int index = findContactIndex(name);
    if (index != -1) {
        phonebook[index] = Contact{"", ""};
        hashTable[index] = 0;
        cout << "Contact deleted.\n";
    } else {
        cout << "Contact not found.\n";
    }
}

// Display all contacts alphabetically
void displayContacts() {
    Contact sorted[MAX_CONTACTS];
    int count = 0;
    for (int i = 0; i < MAX_CONTACTS; ++i) {
        if (hashTable[i] == 1) {
            sorted[count++] = phonebook[i];
        }
    }

    // Simple bubble sort
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (sorted[j].name > sorted[j + 1].name) {
                swap(sorted[j], sorted[j + 1]);
            }
        }
    }

    cout << left << setw(20) << "Name" << "Phone Number\n";
    cout << "-------------------- -------------------\n";
    for (int i = 0; i < count; ++i) {
        cout << left << setw(20) << sorted[i].name << sorted[i].phoneNumber << "\n";
    }
}

// Save contacts to file
void saveToFile() {
    ofstream file("contacts.txt");
    for (int i = 0; i < MAX_CONTACTS; ++i) {
        if (hashTable[i] == 1) {
            file << phonebook[i].name << "," << phonebook[i].phoneNumber << "\n";
        }
    }
    file.close();
    cout << "Contacts saved to file.\n";
}

// Load contacts from file
void loadFromFile() {
    ifstream file("contacts.txt");
    if (!file.is_open()) {
        cout << "No saved contacts found.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        size_t comma = line.find(',');
        if (comma != string::npos) {
            string name = line.substr(0, comma);
            string phone = line.substr(comma + 1);
            addContact(name, phone);
        }
    }
    file.close();
    cout << "Contacts loaded from file.\n";
}

// Menu
void showMenu() {
    cout << "\n==== Phonebook Menu ====\n";
    cout << "1. Add Contact\n";
    cout << "2. Search Contact\n";
    cout << "3. Update Contact\n";
    cout << "4. Delete Contact\n";
    cout << "5. Display All Contacts\n";
    cout << "6. Save Contacts to File\n";
    cout << "7. Load Contacts from File\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    char choice;
    loadFromFile(); // Auto-load on start

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1': {
                string name, phone;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phone);
                addContact(name, phone);
                break;
            }
            case '2': {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                searchContact(name);
                break;
            }
            case '3': {
                string name;
                cout << "Enter name to update: ";
                getline(cin, name);
                updateContact(name);
                break;
            }
            case '4': {
                string name;
                cout << "Enter name to delete: ";
                getline(cin, name);
                deleteContact(name);
                break;
            }
            case '5':
                displayContacts();
                break;
            case '6':
                saveToFile();
                break;
            case '7':
                loadFromFile();
                break;
            case '8':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != '8');

    return 0;
}
