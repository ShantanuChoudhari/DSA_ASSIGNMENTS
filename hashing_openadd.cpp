#include <iostream>
#include <string>
using namespace std;

const int n = 10; // size of hash table

struct User {
    string username;
    string password;
    bool occupied;
};

class HashTable {
    User table[n];

public:
    HashTable() {
        for (int i = 0; i < n; i++)
            table[i].occupied = false;
    }

    int hashFunction(string key) {
        int sum = 0;
        for (char c : key) sum += c;
        return sum % n;
    }

    // Insert user
    void insertUser(string username, string password) {
        int index = hashFunction(username);
        int count = 0;

        while (table[index].occupied && count < n) {
            if (table[index].username == username) {
                cout << "User already exists!\n";
                return;
            }
            index = (index + 1) % n;
            count++;
        }

        if (count == n) {
            cout << "Hash table full! Cannot insert.\n";
            return;
        }

        table[index].username = username;
        table[index].password = password;
        table[index].occupied = true;
        cout << "Inserted [" << username << "] at index " << index << endl;
    }

    // Delete user
    void deleteUser(string username) {
        int index = hashFunction(username);
        int count = 0;

        while (table[index].occupied && count < n) {
            if (table[index].username == username) {
                table[index].occupied = false;
                table[index].username = "";
                table[index].password = "";
                cout << "User '" << username << "' deleted from index " << index << endl;
                return;
            }
            index = (index + 1) % n;
            count++;
        }

        cout << "User '" << username << "' not found.\n";
    }

    // Search user
    void searchUser(string username) {
        int index = hashFunction(username);
        int count = 0;

        while (table[index].occupied && count < n) {
            if (table[index].username == username) {
                cout << "User found at index " << index << endl;
                cout << "Username: " << table[index].username << endl;
                cout << "Password: " << table[index].password << endl;
                return;
            }
            index = (index + 1) % n;
            count++;
        }

        cout << "User '" << username << "' not found.\n";
    }

    // Display table
    void display() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            if (table[i].occupied)
                cout << "[" << table[i].username << ", " << table[i].password << "]";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice;
    string username, password;

    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Add User\n";
        cout << "2. Delete User\n";
        cout << "3. Search User\n";
        cout << "4. Display Table\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                ht.insertUser(username, password);
                break;

            case 2:
                cout << "Enter username to delete: ";
                cin >> username;
                ht.deleteUser(username);
                break;

            case 3:
                cout << "Enter username to search: ";
                cin >> username;
                ht.searchUser(username);
                break;

            case 4:
                ht.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}
