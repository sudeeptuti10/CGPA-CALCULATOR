#include<iostream>
#include<fstream>
using namespace std;

class CGPA {
private:
    string name;
    int id;
    int n;
    string courseName[10];
    string grade[10];
    int credit[10];
    float gradePoint[10];
    float cgpa;

public:

    void inputDetails() {

        cout << "Enter the Name of the Student: ";
        cin >> name;

        cout << "Enter the Student ID: ";
        cin >> id;

        cout << "Enter how many courses Student have: ";
        cin >> n;

        for(int i = 0; i < n; i++) {

            cout << "Enter Course Name: ";
            cin >> courseName[i];

            cout << "Enter Grade (A+/A/B+/B/C/D/F): ";
            cin >> grade[i];

            cout << "Enter Credit Hours: ";
            cin >> credit[i];

            if(grade[i] == "A+")
                gradePoint[i] = 10;

            else if(grade[i] == "A")
                gradePoint[i] = 9;

            else if(grade[i] == "B+")
                gradePoint[i] = 8;

            else if(grade[i] == "B")
                gradePoint[i] = 7;

            else if(grade[i] == "C")
                gradePoint[i] = 6;

            else if(grade[i] == "D")
                gradePoint[i] = 5;

            else if(grade[i] == "F")
                gradePoint[i] = 0;

            else {
                gradePoint[i] = 0;
                cout << "Invalid Grade Entered!";
            }
        }
    }

    void calculateCGPA() {

        int totalCredits = 0;
        float totalGradePoints = 0;

        cout << "\n----- Course Details -----\n";

        for(int i = 0; i < n; i++) {

            float points = gradePoint[i] * credit[i];

            cout << "\nCourse: " << courseName[i];
            cout << "\nGrade: " << grade[i];
            cout << "\nCredits: " << credit[i];
            cout << "\nGrade Points: " << points << endl;

            totalCredits += credit[i];
            totalGradePoints += points;
        }

        cgpa = totalGradePoints / totalCredits;

        cout << "\n--------------------------";
        cout << "\nTotal Credits = " << totalCredits;
        cout << "\nTotal Grade Points = " << totalGradePoints;
        cout << "\nFinal CGPA = " << cgpa;
    }

    void storeData() {

        ofstream fout;

        fout.open("cgpa.txt", ios::app);

        if(!fout) {

            cout << "\nFile Creation Failed";
        }

        else {

            fout << "\n===== Student Details =====\n";

            fout << "Name: " << name << endl;
            fout << "ID: " << id << endl;
            fout << "Number of Courses: " << n << endl;

            for(int i = 0; i < n; i++) {

                fout << "\nCourse Name: " << courseName[i] << endl;
                fout << "Grade: " << grade[i] << endl;
                fout << "Credit Hours: " << credit[i] << endl;
                fout << "Grade Point: " << gradePoint[i] << endl;
            }

            fout << "\nCGPA: " << cgpa << endl;

            
        }

        fout.close();
    }

    void viewAllData() {

        ifstream fin;

        fin.open("cgpa.txt", ios::in);

        if(!fin) {

            cout << "\nFile Not Found";
        }

        else {

            char ch;

            while(fin.get(ch)) {

                cout << ch;
            }
        }

        fin.close();
    }
};

int main() {

    CGPA c;

    c.inputDetails();
    c.calculateCGPA();
    c.storeData();
    c.viewAllData();
    return 0;
}