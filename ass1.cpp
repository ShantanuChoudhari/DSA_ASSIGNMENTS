/*"Efficient Data Management Using Linked Lists: Implementing
Dynamic Operations for Contact Management System"
Utilize Singly and Doubly Linked Lists to manage a Contact
Management System. The system will support key operations such as:
• Creating a contact list dynamically.
• Adding new contacts efficiently.
• Deleting contacts when no longer needed.
• Searching for specific contacts based on name or number.
• Reversing the contact list for alternate viewing orders.
• Traversing through the list to display all stored contacts.
Name = Shantanu_Choudhari
Roll-No = 23304*/
#include <iostream>
#include <string>
using namespace std;

// Structure to represent each contact node
struct Contact {
    string name;
    string phone;
    string email;
    Contact* next;
};

// Class to manage the list operations
class List {
private:
    Contact* head;

    // // Helper function to validate email
    // bool isValidEmail(const string& email) {
    //     return (email.find('@') != string::npos &&
    //             email.find("gmail.com") != string::npos);
    // }

public:
    List() {
        head = NULL;
    }

    // Create new node
    Contact* createnode(string name, string phone, string email) {
        // if (!isValidEmail(email)) {
        //     cout << " Invalid email! Must contain '@' and 'gmail.com'\n";
        //     return NULL;
        // }

        Contact* newnode = new Contact();
        newnode->name = name;
        newnode->phone = phone;
        newnode->email = email;
        newnode->next = NULL;
        return newnode;
    }

    // Insert at Beginning
    void insertatstart(string name, string phone, string email) {
        Contact* newnode = createnode(name, phone, email);
        if (newnode == NULL) return;

        newnode->next = head;
        head = newnode;
        cout << " Contact inserted at beginning.\n";
    }

    // Insert at End
    void insertattail(string name, string phone, string email) {
        Contact* newnode = createnode(name, phone, email);
        if (newnode == NULL) return;

        if (head == NULL) {
            head = newnode;
        } else {
            Contact* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cout << " Contact inserted at end.\n";
    }

    // Insert at specific position
    void insertAtPosition(string name, string phone, string email, int position) {
        if (position == 1) {
            insertatstart(name, phone, email);
            return;
        }

        Contact* newnode = createnode(name, phone, email);
        if (newnode == NULL) return;

        Contact* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                cout << " Position out of range.\n";
                delete newnode;
                return;
            }
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        cout << " Contact inserted at position " << position << ".\n";
    }

    // Delete at Beginning
    void deleteatstart() {
        if (head == NULL) {
            cout << " List is empty.\n";
            return;
        }
        Contact* temp = head;
        head = head->next;
        delete temp;
        cout << " Contact deleted from beginning.\n";
    }

    // Delete at End
    void deleteatend() {
        if (head == NULL) {
            cout << " List is empty.\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Contact* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        cout << " Contact deleted from end.\n";
    }

    // Delete at specific position
    void deleteatposition(int position) {
        if (head == NULL) {
            cout << " List is empty.\n";
            return;
        }

        if (position == 1) {
            deleteatstart();
            return;
        }

        Contact* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL || temp->next == NULL) {
                cout << " Position out of range.\n";
                return;
            }
            temp = temp->next;
        }

        Contact* todel = temp->next;
        if (todel == NULL) {
            cout << " Position out of range.\n";
            return;
        }

        temp->next = todel->next;
        delete todel;
        cout << " Contact deleted at position " << position << ".\n";
    }

    // Search by name
    void searchContact(string name) {
        Contact* temp = head;
        int position = 1;
        while (temp != NULL) {
            if (temp->name == name) {
                cout << " Contact found at position " << position << ":\n";
                cout << "Name: " << temp->name << ", Phone: " << temp->phone << ", Email: " << temp->email << "\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << " Contact not found.\n";
    }

    // Reverse the contact list
void reverseList() {
    Contact* prev = NULL;
    Contact* current = head;
    Contact* next = NULL;

    while (current != NULL) {
        next = current->next;    // Store next node
        current->next = prev;    // Reverse current node's pointer
        prev = current;          // Move prev and current one step forward
        current = next;
    }
    head = prev;
    cout << " Contact list reversed.\n";
}


    // Display all contacts
    void displayContacts() {
        if (head == NULL) {
            cout << " Contact list is empty.\n";
            return;
        }

        Contact* temp = head;
        cout << "\n Contact List:\n";
        while (temp != NULL) {
            cout << "Name: " << temp->name << ", Phone: " << temp->phone << ", Email: " << temp->email << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    List contactList;
    int choice, position;
    string name, phone, email;

    while (true) {
        cout << "\n====== Contact Management Menu ======\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n";
        cout << "7. Search Contact\n8. Display All Contacts\n9.Exit\n 10.reverse a system\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name, Phone, Email: ";
                cin >> name >> phone >> email;
                contactList.insertatstart(name, phone, email);
                break;
            case 2:
                cout << "Enter Name, Phone, Email: ";
                cin >> name >> phone >> email;
                contactList.insertattail(name, phone, email);
                break;
            case 3:
                cout << "Enter Name, Phone, Email and Position: ";
                cin >> name >> phone >> email >> position;
                contactList.insertAtPosition(name, phone, email, position);
                break;
            case 4:
                contactList.deleteatstart();
                break;
            case 5:
                contactList.deleteatend();
                break;
            case 6:
                cout << "Enter Position to Delete: ";
                cin >> position;
                contactList.deleteatposition(position);
                break;
            case 7:
                cout << "Enter Name to Search: ";
                cin >> name;
                contactList.searchContact(name);
                break;
            case 8:
                contactList.displayContacts();
                break;
            case 9:
                cout << "Exiting program....\n";
                return 0;

            case 10:
                contactList.reverseList();
                break;
            default:
                cout << " Invalid choice.\n";
        }
    }
}
/*====== Contact Management Menu ======
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Search Contact
8. Display All Contacts
9.Exit
 10.reverse a system
Enter your choice: 1
Enter Name, Phone, Email: shantanu 7020486040 shan@gmail.com
 Contact inserted at beginning.

====== Contact Management Menu ======
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Search Contact
8. Display All Contacts
9.Exit
 10.reverse a system
Enter your choice: 8

 Contact List:
Name: shantanu, Phone: 7020486040, Email: shan@gmail.com

====== Contact Management Menu ======
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Search Contact
8. Display All Contacts
9.Exit
 10.reverse a system
Enter your choice: 2
Enter Name, Phone, Email: abc 1234567890 abc@gmail.com
 Contact inserted at end.

====== Contact Management Menu ======
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Search Contact
8. Display All Contacts
9.Exit
 10.reverse a system
Enter your choice: 8

 Contact List:
Name: shantanu, Phone: 7020486040, Email: shan@gmail.com
Name: abc, Phone: 1234567890, Email: abc@gmail.com

====== Contact Management Menu ======
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Search Contact
8. Display All Contacts
9.Exit
 10.reverse a system
Enter your choice:*/
