/*#include <iostream>
#include <cstring>
using namespace std;

union student {
    char name[50];
    int rollNumber;
    float cgpa;
    char hostelName[50];
};

struct studentEntry {
    student data;  
    int activeField; 
};

int main() {
    int n, choice;

    cout << "Enter the number of students: ";
    cin >> n;
 

    studentEntry* st = new studentEntry[n];
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for student " << (i + 1) << ":\n";
        cout << "1. Enter Name\n";
        cout << "2. Enter Roll Number\n";
        cout << "3. Enter CGPA\n";
        cout << "4. Enter Hostel Name\n";
        cout << "Choose the field to input (1-4): ";
        cin >> choice;
        cin.ignore(); 

        st[i].activeField = choice;
        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin.getline(st[i].data.name, 50);
                break;

            case 2:
                cout << "Enter Roll Number: ";
                cin >> st[i].data.rollNumber;
                cin.ignore();
                break;

            case 3:
                cout << "Enter CGPA: ";
                cin >> st[i].data.cgpa;
                cin.ignore();
                break;

            case 4:
                cout << "Enter Hostel Name: ";
                cin.getline(st[i].data.hostelName, 50);
                break;

            default:
                cout << "Invalid choice, skipping input for this student.\n";
                st[i].activeField = -1;
        }
    }

    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent " << (i + 1) << ":\n";
        switch (st[i].activeField) {
            case 1:
                cout << "Name: " << st[i].data.name << "\n";
                break;
            case 2:
                cout << "Roll Number: " << st[i].data.rollNumber << "\n";
                break;
            case 3:
                cout << "CGPA: " << st[i].data.cgpa << "\n";
                break;
            case 4:
                cout << "Hostel Name: " << st[i].data.hostelName << "\n";
                break;
            default:
                cout << "No valid data available for this student.\n";
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class definition for Student
class Student {
private:
    int rollNo;
    string name;
    float academicGrade;
    float additionalGrade;
    string activityType; // "Sports" or "Cultural"

public:
    // Constructor
    Student(int r, string n, float ag, float addg, string actType)
        : rollNo(r), name(n), academicGrade(ag), additionalGrade(addg), activityType(actType) {}

    // Function to calculate the average grade
    float calculateAverage() const {
        return (academicGrade + additionalGrade) / 2.0;
    }

    // Function to display student details
    void displayDetails() const {
        cout << "Roll No: " << rollNo << "\n"
             << "Name: " << name << "\n"
             << "Academic Grade: " << academicGrade << "\n"
             << activityType << " Grade: " << additionalGrade << "\n"
             << "Average Grade: " << calculateAverage() << "\n"
             << "-----------------------------------\n";
    }
};

// Main Function
int main() {
    vector<Student*> students; // Vector to store pointers to Student objects
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Input student details
    for (int i = 0; i < numStudents; ++i) {
        int rollNo;
        string name, activityType;
        float academicGrade, additionalGrade;

        cout << "Enter details for Student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> rollNo;
        cin.ignore(); // Clear input buffer
        cout << "Name: ";
        getline(cin, name);
        cout << "Academic Grade: ";
        cin >> academicGrade;

        cout << "Enter activity type (Sports or Cultural): ";
        cin >> activityType;
        cout << "Enter " << activityType << " Grade: ";
        cin >> additionalGrade;

        // Dynamically allocate memory for a Student object
        students.push_back(new Student(rollNo, name, academicGrade, additionalGrade, activityType));
    }

    // Display student details
    cout << "\nAll Student Details:\n";
    for (const auto& student : students) {
        student->displayDetails();
    }

    // Calculate and display overall average grade
    float totalAverage = 0.0;
    for (const auto& student : students) {
        totalAverage += student->calculateAverage();
    }
    cout << "Overall Average Grade: " << totalAverage / numStudents << "\n";

    // Free dynamically allocated memory
    for (auto& student : students) {
        delete student;
    }
    students.clear();

    return 0;
}
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    char academicGrade;   
    char additionalGrade; 
    string activityType;  

public:
    
    Student(int r, string n, char ag, char addg, string actType)
        : rollNo(r), name(n), academicGrade(ag), additionalGrade(addg), activityType(actType) {}

    int gradeToNumeric(char grade) const {
        if (grade == 'A') return 100;
        if (grade == 'B') return 90;
        if (grade == 'C') return 80;
        if (grade == 'D') return 70;
        if (grade == 'E') return 50;  
        return 40; 
    }

    float calculateAverage() const {
        int academicNumeric = gradeToNumeric(academicGrade);
        int additionalNumeric = gradeToNumeric(additionalGrade);
        return (academicNumeric + additionalNumeric) / 2.0;
    }

    char numericToGrade(float average) const {
        if (average >= 95) return 'A';
        else if (average >= 85) return 'B';
        else if (average >= 75) return 'C';
        else if (average >= 55) return 'D';
        else if (average >= 45) return 'E';  
        return 'F';
    }

    void displayDetails() const {
        float average = calculateAverage();
        cout << "Roll No: " << rollNo << "\n"
             << "Name: " << name << "\n"
             << "Academic Grade: " << academicGrade << "\n"
             << activityType << " Grade: " << additionalGrade << "\n"
             << "Average Grade (Numeric): " << average << "\n"
             << "Average Grade (Letter): " << numericToGrade(average) << "\n";
    }
};

int main() {
    vector<Student*> students; 
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        int rollNo;
        string name, activityType;
        char academicGrade, additionalGrade;

        cout << "Enter details for Student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> rollNo;
        cin.ignore(); 
        cout << "Name: ";
        getline(cin, name);
        cout << "Academic Grade (A, B, C, D, E, F): ";
        cin >> academicGrade;

        cout << "Enter activity type (Sports or Cultural): ";
        cin >> activityType;
        cout << "Enter " << activityType << " Grade (A, B, C, D, E, F): ";
        cin >> additionalGrade;

        students.push_back(new Student(rollNo, name, academicGrade, additionalGrade, activityType));
    }

    cout << "\nAll Student Details:\n";
    for (const auto& student : students) {
        student->displayDetails();
    }

    float totalAverage = 0.0;
    for (const auto& student : students) {
        totalAverage += student->calculateAverage();
    }
    cout << "Overall Average Grade: " << totalAverage / numStudents << "\n";

    for (auto& student : students) {
        delete student;
    }
    students.clear();

    return 0;
}

