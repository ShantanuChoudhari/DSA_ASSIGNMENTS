/*Assignment 3:
 Searching and sorting
 
 Searching and Sorting
Consider a student database of SEIT class (at least 15 records). Database
contains different fields of every student like Roll No, Name and SGPA.
(array of structure)
a) Design a roll call list, arrange list of students according to roll
numbers in ascending order (Use Bubble Sort)
b) Arrange a list of students alphabetically. (Use Insertion sort)
c) Arrange a list of students to find out the first ten toppers from a class.
(Use Quick sort)
d) Search for students according to SGPA. If more than one student has
the same SGPA, then print a list of all students having the same SGPA.
e) Search for a particular student according to name using binary search
without recursion. (all the student records having the presence of search
key should be displayed)
(Note: Implement either Bubble sort or Insertion Sort.)
Name = SHANTANU_CHOUDHARI
ROLL =23304*/

#include <bits/stdc++.h>
using namespace std;

struct Student {
    int roll;
    string name;
    float sgpa;
};

void mybubblesort(Student arr[], int n) {   //bubblesort to check pairs
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {   // to avoid resorting
            if (arr[j].roll > arr[j + 1].roll)
                swap(arr[j], arr[j + 1]);
        }
    }
}

void myinsertionsort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {       //considering 1 ele as sorted
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].name > key.name) {
            arr[j + 1] = arr[j];
            j--;                                   //for updation of key
        }
        arr[j + 1] = key;
    }
}

int partition(Student arr[], int low, int high) {
    float pivot = arr[high].sgpa;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].sgpa > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void myquicksort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        myquicksort(arr, low, pi - 1);
        myquicksort(arr, pi + 1, high);
    }
}

void mylinearsearch(Student arr[], int n, float sgpa) {    
    bool found = false;                     //flag to check
    for (int i = 0; i < n; i++) {
        if (arr[i].sgpa == sgpa) {
            cout << "Roll: " << arr[i].roll << ", Name: " << arr[i].name << ", SGPA: " << arr[i].sgpa << "\n";
            found = true;
        }
    }
    if (!found) cout << "No student found with SGPA " << sgpa << "\n";
}

int mybinarysearch(Student arr[], int n, string key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].name == key) {
            cout<<"entry found "<<endl;
            return mid; // found
        }
        else if (arr[mid].name < key) {       //search in right half
            left = mid + 1;
        }
        else {
            right = mid - 1;                //search in left half
        }
    }
    return -1; // not found
}

void display(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].roll << "\t" << arr[i].name << "\t" << arr[i].sgpa << "\n";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Student students[n];     

    for (int i = 0; i < n; i++) {
        cout << "Enter Roll Number, Name, SGPA for student " << i + 1 << ": ";
        cin >> students[i].roll >> students[i].name >> students[i].sgpa;
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display all students\n";
        cout << "2. Sort by Roll Number (Bubble Sort)\n";
        cout << "3. Sort by Name (Insertion Sort)\n";
        cout << "4. Sort by SGPA (Quick Sort)\n";
        cout << "5. Search by SGPA (Linear Search)\n";
        cout << "6. Search by Name (Binary Search)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            display(students, n);
            break;
        case 2:
         mybubblesort(students, n);
            cout << "Sorted by Roll:\n";
            display(students, n);
            break;
        case 3:
            myinsertionsort(students, n);
            cout << "Sorted by Name:\n";
            display(students, n);
            break;
        case 4:
            myquicksort(students, 0, n - 1);
            cout << "Sorted by SGPA:\n";
            display(students, n);
            break;
        case 5: {
            float sg;
            cout << "Enter SGPA to search: ";
            cin >> sg;
            mylinearsearch(students, n, sg);
            break;
        }
        case 6: {
            myinsertionsort(students, n);       //before bs perform sorting function
            string key;
            cout << "Enter name or part to search: ";
            cin >> key;
           mybinarysearch(students, n, key);
            break;
        }
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
/*Enter number of students: 5
Enter Roll Number, Name, SGPA for student 1: 1 abc 9.8
Enter Roll Number, Name, SGPA for student 2: 2 cde 9.7
Enter Roll Number, Name, SGPA for student 3: 3 efg 6.8
Enter Roll Number, Name, SGPA for student 4: 4 hij 9.9
Enter Roll Number, Name, SGPA for student 5: 5 klm 8.9

Menu:
1. Display all students
2. Sort by Roll Number (Bubble Sort)
3. Sort by Name (Insertion Sort)
4. Sort by SGPA (Quick Sort)
5. Search by SGPA (Linear Search)
6. Search by Name (Binary Search)
7. Exit
Enter your choice: 2
Sorted by Roll:
1       abc     9.8
2       cde     9.7
3       efg     6.8
4       hij     9.9
5       klm     8.9


Menu:
1. Display all students
2. Sort by Roll Number (Bubble Sort)
3. Sort by Name (Insertion Sort)
4. Sort by SGPA (Quick Sort)
5. Search by SGPA (Linear Search)
6. Search by Name (Binary Search)
7. Exit
Enter your choice: 3
Sorted by Name:
1       abc     9.8
2       cde     9.7
3       efg     6.8
4       hij     9.9
5       klm     8.9


Menu:
1. Display all students
2. Sort by Roll Number (Bubble Sort)
3. Sort by Name (Insertion Sort)
4. Sort by SGPA (Quick Sort)
5. Search by SGPA (Linear Search)
6. Search by Name (Binary Search)
7. Exit
Enter your choice: 6
Enter name or part to search: abc
entry found

Menu:
1. Display all students
2. Sort by Roll Number (Bubble Sort)
3. Sort by Name (Insertion Sort)
4. Sort by SGPA (Quick Sort)
5. Search by SGPA (Linear Search)
6. Search by Name (Binary Search)
7. Exit
Enter your choice:*/