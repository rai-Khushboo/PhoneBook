# 📒 Phonebook CLI Application (C++)

A simple and interactive command-line phonebook application built with **C++**.  
Uses **hash tables** and **linear probing** for efficient storage and retrieval of contact information.

---

## 🚀 Features

- 📇 Add new contacts
- 🔍 Search contacts by name
- ✏️ Update existing contacts
- ❌ Delete contacts
- 📃 Display all contacts (alphabetically sorted)
- 💾 Save contacts to a `.txt` file
- 📂 Load contacts from file on startup
- 🧠 Hashing + Collision Handling (Linear Probing)
- 📞 Phone number validation
- 📦 Exportable and persistent storage

---

## 🛠️ Technologies Used

- 💻 Language: **C++**
- ⚙️ Compiler: **g++** (MinGW / GCC)
- 📚 Data Structures: Hash Table, Arrays
- 📄 File I/O: Text File Read/Write
- 🔁 Algorithms: Linear Probing, Bubble Sort

---

## 📁 File Structure

📦 PhonebookCLI/
├── phonebook.cpp # Main C++ source file
├── contacts.txt # Saved contacts (auto-generated)
└── README.md # Project documentation (this file)


---

## 💻 How to Compile and Run (on Windows CMD)

> ⚠️ Make sure `g++` is installed and added to your PATH. If not, install via [MinGW](https://sourceforge.net/projects/mingw/)

### ✅ Step-by-Step

1. Open **Command Prompt**
2. Navigate to the folder where `phonebook.cpp` is saved:
   ```bash
   cd C:\Path\To\Your\File

3. Compile the program:
  `g++ phonebook.cpp -o phonebook.exe`
4. Run the executable:
  `phonebook.exe`

## 🧪Sample Output
==== Phonebook Menu ====
1. Add Contact
2. Search Contact
3. Update Contact
4. Delete Contact
5. Display All Contacts
6. Save Contacts to File
7. Load Contacts from File
8. Exit
   
Enter your choice:

## 💾 Sample contacts.txt (auto-created)
Khushi,+123456789

Yashi,+987654321

## 📚 Concepts Demonstrated

📦 Hash tables with collision handling (linear probing)
🧠 Sorting algorithms (bubble sort)
🗃️ Persistent data storage using file I/O
🧪 Input validation
🧱 Procedural programming with modular functions

✍️ Author

**Khushboo**
