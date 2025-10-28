#include <iostream>
#include <string>

using namespace std;

class Patient {
public:
    string name;
    int priority;
    Patient* next;

    Patient(string n, int p) : name(n), priority(p), next(nullptr) {}

    void display() const {
        cout << name << " (Priority: " << priority << ")" << endl;
    }
};

class HospitalPriorityQueue {
private:
    Patient* head;

public:
    HospitalPriorityQueue() : head(nullptr) {}

    // Add patient at end (unsorted)
    void addPatient(const string& name, int priority) {
        Patient* newPatient = new Patient(name, priority);
        if (!head) {
            head = newPatient;
        } else {
            Patient* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newPatient;
        }
        cout << "Patient added successfully.\n";
    }

    // Find and treat highest priority patient
    Patient* treatPatient() {
        if (!head) {
            cout << "No patients to treat.\n";
            return nullptr;
        }

        Patient* current = head;
        Patient* highestPriorityPatient = head;
        Patient* prev = nullptr;
        Patient* prevHighest = nullptr;

        // Traverse to find highest priority and keep track of previous nodes
        while (current != nullptr) {
            if (current->priority > highestPriorityPatient->priority) {
                highestPriorityPatient = current;
                prevHighest = prev;
            }
            prev = current;
            current = current->next;
        }

        // Remove highestPriorityPatient from list
        if (prevHighest == nullptr) {
            // highest priority patient is at head
            head = head->next;
        } else {
            prevHighest->next = highestPriorityPatient->next;
        }
        highestPriorityPatient->next = nullptr; // disconnect from list
        return highestPriorityPatient;
    }

    void showAllPatients() const {
        if (!head) {
            cout << "No patients in queue.\n";
            return;
        }
        cout << "Current Patients in Queue:\n";
        Patient* temp = head;
        while (temp) {
            temp->display();
            temp = temp->next;
        }
    }

    ~HospitalPriorityQueue() {
        // Cleanup memory
        Patient* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    HospitalPriorityQueue hospitalQueue;
    int choice;

    do {
        cout << "\nHospital Management System Menu:\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Patient\n";
        cout << "3. Show All Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int priority;
                cout << "Enter patient name: ";
                cin >> ws; // consume whitespace
                getline(cin, name);
                cout << "Enter patient priority (higher number = higher priority): ";
                cin >> priority;
                hospitalQueue.addPatient(name, priority);
                break;
            }
            case 2: {
                Patient* treated = hospitalQueue.treatPatient();
                if (treated) {
                    cout << "Treating patient: ";
                    treated->display();
                    delete treated;  // free memory after treating
                }
                break;
            }
            case 3:
                hospitalQueue.showAllPatients();
                break;
            case 4:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
