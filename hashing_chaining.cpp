#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;    
const int CHAIN = 5;     

string usernames[SIZE][CHAIN]; 
string rollnumber[SIZE][CHAIN];  

//(sum of ASCII values)
int hashFunction(string name) {
    int sum = 0;
    for (int i = 0; i < name.length(); i++)
        sum += name[i];
    return sum % SIZE;
}


string hashroll_number(string pass) {

    return pass;
}


void insertUser(string name, string pass) {
    int index = hashFunction(name);
    string hashedPass = hashroll_number(pass);

    
    for (int i = 0; i < CHAIN; i++) {
        if (usernames[index][i] == "") {
            usernames[index][i] = name;
            rollnumber[index][i] = hashedPass;
            cout << " User '" << name << "' inserted at index " << index << ", position " << i << endl;
            return;
        }
    }
    cout << " No space in chain for index " << index << endl;
}

// Search for a user
void searchUser(string name) {
    int index = hashFunction(name);

    for (int i = 0; i < CHAIN; i++) {
        if (usernames[index][i] == name) {
            cout << " Found user '" << name << "' at index " << index << ", position " << i << endl;
            cout << "Hashed roll_number: " << rollnumber[index][i] << endl;
            return;
        }
    }
    cout << " User not found!\n";
}

// Display hash table
void displayTable() {
    cout << "\n--- HASH TABLE (Array Chaining) ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << i << "] -> ";
        bool empty = true;
        for (int j = 0; j < CHAIN; j++) {
            if (usernames[i][j] != "") {
                cout << "(" << usernames[i][j] << ", " << rollnumber[i][j] << ") ";
                empty = false;
            }
        }
        if (empty) cout << "Empty";
        cout << endl;
        
    }
}

int main() {
    int choice;
    string name, pass;

    // Initialize arrays to empty
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < CHAIN; j++)
            usernames[i][j] = rollnumber[i][j] = "";

    do {
        cout << "\n1. Insert User\n2. Search User\n3. Display Table\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter roll_number: ";
            cin >> pass;
            insertUser(name, pass);
            break;

        case 2:
            cout << "Enter username to search: ";
            cin >> name;
            searchUser(name);
            break;

        case 3:
            displayTable();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}