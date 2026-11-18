#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Student {
private:
    char* name;
    int rollNo;
    float marks;
    static int count;

public:
    // Parameterized constructor
    Student(const char* n, int r, float m) : rollNo(r), marks(m) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        ++count;
    }

    // Copy constructor performs a deep copy
    Student(const Student& other) : rollNo(other.rollNo), marks(other.marks) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        ++count;
    }

    // Destructor releases dynamically allocated memory
    ~Student() {
        delete[] name;
        --count;
    }

    // Function overloading
    void display() const {
        cout << left << setw(12) << name
             << setw(10) << rollNo << fixed << setprecision(1)
             << marks << endl;
    }

    void display(bool showResult) const {
        display();
        if (showResult) {
            cout << "Result: " << (marks >= 40.0f ? "Pass" : "Fail") << endl;
        }
    }

    // Static member function
    static int getCount() {
        return count;
    }

    const char* getName() const {
        return name;
    }

    // Operator overloading
    bool operator>(const Student& other) const {
        return marks > other.marks;
    }

    // Friend function declaration
    friend void showMarks(const Student& student);
};

// Definition of static data member
int Student::count = 0;

// Friend function can access private data
void showMarks(const Student& student) {
    cout << student.name << " scored " << student.marks << " marks." << endl;
}

int main() {
    cout << "Initial student count: " << Student::getCount() << endl;

    Student s1("Asha", 101, 78.5f);
    Student s2("Ravi", 102, 65.0f);
    Student s3("Meena", 103, 91.0f);

    cout << "\n--- Student Details ---" << endl;
    cout << left << setw(12) << "Name" << setw(10) << "Roll No" << "Marks" << endl;
    s1.display();
    s2.display(true);
    s3.display(true);

    cout << "\n--- Friend Function ---" << endl;
    showMarks(s1);
    showMarks(s3);

    cout << "\n--- Comparison using > operator ---" << endl;
    if (s1 > s2)
        cout << s1.getName() << " has higher marks than " << s2.getName() << endl;
    else
        cout << s2.getName() << " has higher marks than " << s1.getName() << endl;

    if (s3 > s1)
        cout << s3.getName() << " has higher marks than " << s1.getName() << endl;
    else
        cout << s1.getName() << " has higher marks than " << s3.getName() << endl;

    cout << "\n--- Static Member and Dynamic Object ---" << endl;
    cout << "Current student count: " << Student::getCount() << endl;
    Student* s4 = new Student("Kiran", 104, 55.0f);
    cout << "After creating dynamic object: " << Student::getCount() << endl;
    delete s4;
    cout << "After deleting dynamic object: " << Student::getCount() << endl;

    cout << "\nProgram completed successfully." << endl;
    return 0;
}
