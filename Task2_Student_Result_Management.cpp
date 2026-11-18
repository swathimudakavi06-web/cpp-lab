#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
using namespace std;

// Base class: common details of every student.
class Student {
protected:
    string name;
    int rollNo;
public:
    Student(const string& n, int r) : name(n), rollNo(r) {}
    virtual void display() const = 0; // runtime polymorphism
    virtual ~Student() {}
};

// Derived class: stores marks and calculates the result.
class Result : public Student {
private:
    vector<int> marks;
public:
    Result(const string& n, int r, const vector<int>& m) : Student(n, r), marks(m) {
        if (marks.empty())
            throw invalid_argument("A student must have at least one subject mark.");
        for (int mark : marks) {
            if (mark < 0 || mark > 100)
                throw out_of_range("Marks must be between 0 and 100.");
        }
    }

    int totalMarks() const {
        int total = 0;
        for (int mark : marks) total += mark;
        return total;
    }

    double averageMarks() const {
        return static_cast<double>(totalMarks()) / marks.size();
    }

    string resultStatus() const {
        for (int mark : marks)
            if (mark < 35) return "Fail";
        return "Pass";
    }

    void display() const override {
        cout << left << setw(12) << name << setw(10) << rollNo
             << setw(12) << totalMarks() << setw(12) << fixed << setprecision(2)
             << averageMarks() << resultStatus() << '\n';
    }

    string fileRecord() const {
        string record = name + "," + to_string(rollNo);
        for (int mark : marks) record += "," + to_string(mark);
        record += ",Total=" + to_string(totalMarks()) + ",Result=" + resultStatus();
        return record;
    }
};

int main() {
    cout << "===== STUDENT RESULT MANAGEMENT SYSTEM =====\n\n";
    vector<Result> students;

    try {
        students.emplace_back("Asha", 101, vector<int>{78, 85, 91});
        students.emplace_back("Ravi", 102, vector<int>{67, 72, 69});
        students.emplace_back("Meena", 103, vector<int>{92, 88, 95});
        students.emplace_back("Kiran", 104, vector<int>{28, 64, 70});

        // Demonstrate exception handling for invalid marks.
        try {
            students.emplace_back("Invalid", 105, vector<int>{80, 112, 75});
        } catch (const exception& e) {
            cout << "Invalid record rejected: " << e.what() << "\n\n";
        }

        // Virtual function calls through base-class pointers demonstrate runtime polymorphism.
        cout << "STUDENT DETAILS\n";
        cout << left << setw(12) << "Name" << setw(10) << "Roll No"
             << setw(12) << "Total" << setw(12) << "Average" << "Status\n";
        cout << string(56, '-') << '\n';
        vector<const Student*> studentView;
        for (const Result& record : students) studentView.push_back(&record);
        for (const Student* student : studentView) student->display();

        // Lambda expression with STL count_if algorithm.
        const int cutoff = 240;
        int aboveCutoff = count_if(students.begin(), students.end(),
            [cutoff](const Result& student) { return student.totalMarks() > cutoff; });
        cout << "\nStudents scoring above " << cutoff << " total marks: " << aboveCutoff << '\n';

        // File handling: write all records, then read them back.
        ofstream outFile("student_results.txt");
        if (!outFile) throw runtime_error("Unable to open file for writing.");
        for (const Result& student : students) outFile << student.fileRecord() << '\n';
        outFile.close();
        cout << "\nRecords saved to student_results.txt successfully.\n";

        ifstream inFile("student_results.txt");
        if (!inFile) throw runtime_error("Unable to open file for reading.");
        cout << "\nRETRIEVED RECORDS FROM FILE\n";
        string line;
        while (getline(inFile, line)) cout << line << '\n';
        inFile.close();

        cout << "\nProgram completed successfully.\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
