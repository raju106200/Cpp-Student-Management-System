
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    int choice, roll, searchRoll;
    string name;
    float marks;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            ofstream file("students.txt", ios::app);

            cout << "Enter Roll Number: ";
            cin >> roll;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter Marks: ";
            cin >> marks;

            file << roll << "|" << name << "|" << marks << endl;

            file.close();

            cout << "Student Added Successfully!\n";
        }

        else if (choice == 2)
        {
            ifstream file("students.txt");

            cout << "\n----- Student Records -----\n";

            while (getline(file, name, '|'))
            {
                string studentName, marksText;
                getline(file, studentName, '|');
                getline(file, marksText);

                cout << "Roll Number: " << name << endl;
                cout << "Name: " << studentName << endl;
                cout << "Marks: " << marksText << endl;
                cout << "-------------------------\n";
            }

            file.close();
        }

        else if (choice == 3)
        {
            ifstream file("students.txt");
            bool found = false;

            cout << "Enter Roll Number to Search: ";
            cin >> searchRoll;

            string rollText, studentName, marksText;

            while (getline(file, rollText, '|'))
            {
                getline(file, studentName, '|');
                getline(file, marksText);

                if (stoi(rollText) == searchRoll)
                {
                    cout << "\nStudent Found!\n";
                    cout << "Roll Number: " << rollText << endl;
                    cout << "Name: " << studentName << endl;
                    cout << "Marks: " << marksText << endl;

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student Not Found!\n";
            }

            file.close();
        }

        else if (choice == 4)
        {
            cout << "Thank You! Program Closed.\n";
        }

        else
        {
            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 4);

    return 0;
}

