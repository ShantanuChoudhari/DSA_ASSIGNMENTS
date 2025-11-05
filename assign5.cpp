/*Implementation of a Priority Queue  • Develop a priority queue where elements are dequeued based on priority rather than insertion order.  • Support operations such as insertion, deletion, and display
Roll no:: 23304
Name = Shantanu Choudhari*/
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class Patient {
public:
    string name;
    int priority;

    
    Patient(){
        name =" ";
        priority =-1;
    }
    Patient(string n,int p){
          name = n;
          priority = p;
    }

    void display() const {
        cout << name << " (Priority: " << priority << ")" << endl;
    }
};

class task {
private:
    Patient patients[MAX_SIZE];
    int count;

public:
    task(){
        count=0;
    }

    bool addPatient(const Patient& patient) {
        if (count >= MAX_SIZE) {
            cout << "Queue full! Cannot add more patients.\n";
            return false;
        }
        patients[count] = patient;
        count++;
        return true;
    }
    // Patient addpatient(const Patient& patient){
    //     if(count>=MAX_SIZE){
    //         cout<<"queue is full\n";
    //         return ;
    //     }
    //     patients[count] = patient;
    //     count++;
    //     return patient;
    // }

    Patient treatPatient() {
        if (count == 0) {
            cout << "No patients to treat.\n";
            return Patient("", -1);
        }

        // Find index of highest priority patient
        int maxi = 0;
        for (int i = 1; i < count; i++) {
            if (patients[i].priority > patients[maxi].priority) {
                maxi = i;
            }
        }

        Patient toTreat = patients[maxi];

        // Shift patients left to fill the gap
        // for (int i = maxi; i < count - 1; i++) {
        //     patients[i] = patients[i+1];
        // }
        for(int i=count;i>=maxi;i--){
            patients[i]= patients[i+1];
        }
        count--;
        return toTreat;
    }

    void showAllPatients() const {
        if (count == 0) {
            cout << "No patients in queue.\n";
            return;
        }
        cout << "Current Patients in Queue:\n";
        for (int i = 0; i < count; i++) {
            patients[i].display();
        }
    }
};

int main() {
    task hospitalQueue;
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
                cin>>ws;
                getline(cin, name);
                cout << "Enter patient priority (higher number = higher priority): ";
                cin >> priority;
                hospitalQueue.addPatient(Patient(name, priority));
                cout << "Patient added successfully.\n";
                break;
            }
            case 2: {
                Patient treated = hospitalQueue.treatPatient();
                if (treated.priority != -1) {
                    cout << "Treating patient: ";
                    treated.display();
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
/*output

Hospital Management System Menu:
1. Add Patient
2. Treat Patient
3. Show All Patients
4. Exit
Enter your choice: 1
Enter patient name: shantanu
Enter patient priority (higher number = higher priority): 3
Patient added successfully.

Hospital Management System Menu:
1. Add Patient
2. Treat Patient
3. Show All Patients
4. Exit
Enter your choice: 1
Enter patient name: xyz
Enter patient priority (higher number = higher priority): 1
Patient added successfully.

Hospital Management System Menu:
1. Add Patient
2. Treat Patient
3. Show All Patients
4. Exit
Enter your choice: 2
Treating patient: shantanu (Priority: 3)

Hospital Management System Menu:
1. Add Patient
2. Treat Patient
3. Show All Patients
4. Exit
Enter your choice: 3
Current Patients in Queue:
  (Priority: -1)

Hospital Management System Menu:
1. Add Patient
2. Treat Patient
3. Show All Patients
4. Exit
Enter your choice: */
