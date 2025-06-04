/*
id      : 24006958
name    : Muhammad Razin Rahimi Bin Abdul Shukur
email   : muhammad_24006958@utp.edu.my
lab     : 1
*/

#include <iostream>
using namespace std;

struct Student {
    string Id;
    char name[100];
    string email;
    int contact;
};

int main()
{
    Student stuArray[2];
    for (int i = 0; i < 2; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Input Student ID: "; cin >> stuArray[i].Id;
        cout << "Input Student Name: ";
        cin.ignore();
        cin.getline(stuArray[i].name, 100);

        cout << "Input Student Email: "; cin >> stuArray[i].email;
        cout << "Input Student Contact Number: (+60) "; cin >> stuArray[i].contact;
    }

    cout << endl;

    for (int i = 0; i < 2; i++) {
        cout << "===============================" << endl;
        cout << "Student " << i + 1 << endl;
        cout << "ID: " << stuArray[i].Id << endl;
        cout << "Name: " << stuArray[i].name << endl;
        cout << "Email: " << stuArray[i].email << endl;
        cout << "Contact Number: (+60) " << stuArray[i].contact << endl;
        cout << "===============================" << endl;
    }
}

