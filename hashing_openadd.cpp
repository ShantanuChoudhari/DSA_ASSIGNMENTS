#include <iostream>
#include <string>

using namespace std;

struct Entry {
    string userid;
    string hashedPassword;
};

class HashTableOpen {
private:
    int table_size = 10;
    Entry* table;
    string EMPTY_MARKER = "-1";

public:
    HashTableOpen() {
        table = new Entry[table_size];
        for (int i = 0; i < table_size; i++) {
            table[i].userid = EMPTY_MARKER;
        }
    }

    int hashFunction(string key) {
        int sum_of_chars = 0;
        for (int i = 0; i < key.length(); i++) {
            sum_of_chars += key[i];
        }
        return sum_of_chars % 10;
    }

    string securePasswordHash(string password) {
        return password + "_hashed";
    }

    void insert(string userid, string password) {
        int index = hashFunction(userid);
        string hPass = securePasswordHash(password);
        int originalIndex = index;

        while (table[index].userid != EMPTY_MARKER && table[index].userid != userid) {
            index = (index + 1) % table_size;
            if (index == originalIndex) {
                cout << "\n[Error] Hash table is full. Cannot insert '" << userid << "'." << endl;
                return;
            }
        }
        
        if (table[index].userid == userid) {
            cout << "\n[Error] Userid '" << userid << "' already exists." << endl;
            return;
        }

        table[index].userid = userid;
        table[index].hashedPassword = hPass;
        cout << "\n[Success] User '" << userid << "' inserted at index " << index << "." << endl;
    }

    void search(string search_userid) {
        int index = hashFunction(search_userid);
        int originalIndex = index;
        bool found = false;

        while (table[index].userid != EMPTY_MARKER) {
            if (table[index].userid == search_userid) {
                cout << "\n[Found] User: " << table[index].userid << endl;
                cout << "  Hashed Password: " << table[index].hashedPassword << endl;
                found = true;
                break;
            }
            
            index = (index + 1) % table_size;
            if (index == originalIndex) {
                break;
            }
        }

        if (!found) {
            cout << "\n[Not Found] User '" << search_userid << "' was not found." << endl;
        }
    }

    void display() {
        cout << "\n========================================" << endl;
        cout << "   HASH TABLE (Linear Probing)   " << endl;
        cout << "========================================" << endl;
        for (int i = 0; i < table_size; i++) {
            cout << "Index " << i << ": ";
            if (table[i].userid == EMPTY_MARKER) {
                cout << "[ EMPTY ]";
            } else {
                cout << "[User: " << table[i].userid << ", HPass: " << table[i].hashedPassword << "]";
            }
            cout << endl;
        }
        cout << "========================================" << endl;
    }
};

void showMenu() {
    cout << "\n--- Linear Probing Menu ---" << endl;
    cout << "1. Insert a User" << endl;
    cout << "2. Search for a User" << endl;
    cout << "3. Display Hash Table" << endl;
    cout << "4. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    HashTableOpen ht;
    int choice;
    string userid_input, password_input;

    cout << "Hash Table (Linear Probing) with size 10 has been created." << endl;
    
    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "[Error] Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "  Enter userid to insert: ";
                cin >> userid_input;
                cout << "  Enter password: ";
                cin >> password_input;
                ht.insert(userid_input, password_input);
                break;
            case 2:
                cout << "  Enter userid to search for: ";
                cin >> userid_input;
                ht.search(userid_input);
                break;
            case 3:
                ht.display();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "[Error] Invalid choice. Please try 1-4." << endl;
                break;
        }
    }
    return 0;
}