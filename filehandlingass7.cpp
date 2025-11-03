#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct student{
    int roll;
    string name;
    string division;
    string address;
    string dob;
    float percentage;
    float grade;
};
void addrecord();
void searchrecord();
void modifyrecord();
void deleterecord();

int main(){
      int choice;
    do {
        cout << "\n===== Student Record System =====";
        cout << "\n1. Add Record";
        cout << "\n2. Search Record";
        cout << "\n3. Modify Record";
        cout << "\n4. Delete Record";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addrecord(); break;
            case 2: searchrecord(); break;
            case 3: modifyrecord(); break;
            case 4: deleterecord(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}
void addrecord(){
    ofstream file("student.txt",ios::app);
    if(!file){
        cout<<"error in file system\n";
        return ;
    }
    student s;
    cout << "\nEnter Roll Number: ";
    cin >> s.roll;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Division: ";
    getline(cin, s.division);
    cout << "Enter Address: ";
    getline(cin, s.address);
    cout << "Enter Date of Birth: ";
    getline(cin, s.dob);
    cout << "Enter Percentage: ";
    cin >> s.percentage;
    cout << "Enter Grade: ";
    cin >> s.grade;

    file<<s.roll<<" "<<s.name<<" "<<s.division<<" "<<s.address<<" "<<s.dob<<" "<<s.percentage<<" "<<s.grade<<endl;

    cout<<"\n record inserted successfully\n";
    file.close();
}
void searchrecord(){
    ifstream file("student.txt",ios::in);
   if(!file){
    cout<<"error in file system\n";
    return;

   }
   int key;
   cout<<"enter the key to search\n";
   cin>>key;
   bool flag = false;

   student s;
    while (file >> s.roll >> s.name >> s.division >> s.address >> s.dob >> s.percentage >> s.grade){
        if(s.roll==key){
            cout<<"record found\n";
            cout << "Roll No: " << s.roll << "\nName: " << s.name
                 << "\nDivision: " << s.division << "\nAddress: " << s.address
                 << "\nDOB: " << s.dob << "\nPercentage: " << s.percentage
                 << "\nGrade: " << s.grade << endl;
            flag = true;
            break;
        }
    }
    if(!flag){
        cout<<"\n record not found \n";
    }
    file.close();
}
void modifyrecord(){
    ifstream in("student.txt");
    ofstream out("temp.txt");

    if(!in || !out){
        cout<<"error in the opening the file\n";
        return;
    }
        int key;
    bool flag = false;
    cout << "\nEnter Roll Number to Modify: ";
    cin >> key;
    student s;
    while(in>>s.roll>>s.name>>s.division>>s.address>>s.dob>>s.percentage>>s.grade){

        if(s.roll == key){
            flag = true;
            cout<<"\n enter the detail of student\n";
            cout<<"enter the name"<<endl;
            cin>>s.name;
            cout<<"enter the division"<<endl;
            cin>>s.division;
            cout<<"enter the address"<<endl;
            cin>>s.address;
            cout<<"enter the dob"<<endl;
            cin>>s.dob;
            cout<<"enter the percentage"<<endl;
            cin>>s.percentage;
            cout<<"enter the grade\n"<<endl;
            cin>>s.grade;
        }
        out<<s.roll<<" "<<s.name<<" "<<s.division<<" "<<s.address<<" "<<s.dob<<" "<<s.percentage<<" "<<s.grade<<endl;

    }
    in.close();
    out.close();
    remove("student.txt");
    rename("temp.txt","student.txt");

    if(flag){
        cout<<"record modified successfully\n";
    }else{
        cout<<"\n record not found\n";
    }
}
void deleterecord(){
    ifstream in("student.txt");
    ofstream out("temp.txt");

    if(!in||!out){
        cout<<"error in the opening the file"<<endl;
        return;
    }
    int key;
    bool flag = false;
    cout << "\nEnter Roll Number to Delete: ";
    cin >> key;

    student s;
    while(in>>s.roll>>s.name>>s.division>>s.address>>s.dob>>s.percentage>>s.grade){
        if(s.roll == key){
            flag = true;
            cout<<"\n record deleted successfully\n";
            continue;  //not writing to file
        }
        out<<s.roll<<" "<<s.name<<" "<<s.division<<" "<<s.address<<" "<<s.dob<<s.grade<<endl;
    }
    in.close();
    out.close();

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(!flag){
        cout<<"\n entry not found in the set\n";
    }
}