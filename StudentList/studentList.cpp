#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "myDate.h"
#include <string.h>
#include <iomanip>
using namespace std;

struct Student {
    int ID;
    char grade;
    myDate bday;
    string homeTown;
    char name[20];
};
void displayMenu();
myDate createBday();
string toString(myDate);
void populate(Student* a[]);
void populateID(Student* a[]);
void display(Student* a[]);
void sortByName(Student* a[]);
void sortByID(Student* a[]);
void sortByGrade(Student* a[]);
void sortByBday(Student* a[]);
void sortByHometown(Student* a[]);

int main() {
    Student* s1[10];
    populate(s1);
    populateID(s1);
    display(s1);
    int choice = 0;
    while (choice != 6) {
        displayMenu();
        cout << endl << "Choose a menu option: ";
        cin >> choice;

        if (choice == 1) {
            sortByName(s1);
            display(s1);
        }
        else if (choice == 2) {
            sortByID(s1);
            display(s1);
        }
        else if (choice == 3) {
            sortByBday(s1);
            display(s1);
        }
        else if (choice == 4) {
            sortByGrade(s1);
            display(s1);
        }
        else if (choice == 5) {
            sortByHometown(s1);
            display(s1);
        }
        else {
            break;
        }
    }
    return 0;

}

void displayMenu() {
    cout << "1.) Display list sorted by Name" << endl;
    cout << "2.) Display list sorted by Student ID" << endl;
    cout << "3.) Display list sorted by Birthday" << endl;
    cout << "4.) Display list sorted by Grade" << endl;
    cout << "5.) Display list sorted by Hometown" << endl;
    cout << "6.) Exit" << endl;
}
myDate createBday()
{


    myDate date(1, 1, 1995);
    int start = date.Greg2Julian(date.getMonth(), date.getDay(), date.getYear());
    myDate date2(12, 31, 2005);
    int end = date2.Greg2Julian(date2.getMonth(), date2.getDay(), date2.getYear());
    int diff = start - end;
    int randomDays = rand() % diff;
    date.increaseDate(randomDays);
    return date;

}
void populate(Student* a[]) {
    char grades[] = { 'A', 'B', 'C', 'D', 'F' };
    string homeTown[] = { "Fountain Valley", "Hong Kong", "Shibuya", "Long Beach", "London", "Tokyo", "Kyoto", "Osaka", "Shanghai", "Beijing" };
    srand((unsigned int)time(0));
    for (int i = 0; i < 10; i++) {
        a[i] = new Student;
        a[i]->homeTown = homeTown[i];
        a[i]->grade = grades[rand() % 5];
        a[i]->bday = createBday();
    }

    strcpy(a[0]->name, "Jimmy");
    strcpy(a[1]->name, "Bryan");
    strcpy(a[2]->name, "Daniel");
    strcpy(a[3]->name, "Orion");
    strcpy(a[4]->name, "Andy");
    strcpy(a[5]->name, "Kathy");
    strcpy(a[6]->name, "Stephen");
    strcpy(a[7]->name, "Jordan");
    strcpy(a[8]->name, "Britney");
    strcpy(a[9]->name, "Shelly");
}
void display(Student* a[]) {

    cout << setw(10) << left << "Name"
        << setw(15) << left << "Student ID"
        << setw(20) << left << "Birthday"
        << setw(15) << left << "Grade"
        << setw(5) << left << "Hometown"
        << endl << endl;

    for (int i = 0; i < 10; i++) {

        cout << setw(10) << left << a[i]->name << setw(15) << left << a[i]->ID << setw(20) << left << a[i]->bday.toString() << setw(15) << left << a[i]->grade << setw(5) << left << a[i]->homeTown << endl;
    }
}

void populateID(Student* a[]) {
    srand((unsigned int)time(0));
    for (int i = 0; i < 10; i++) {
        int studentID = 1000;
        studentID = studentID + (rand() % 9000);
        a[i]->ID = studentID;
    }
}

void sortByName(Student* a[]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            int num = strcmp(a[j]->name, a[j + 1]->name);
            if (num > 0) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void sortByID(Student* a[]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (a[j]->ID > a[j + 1]->ID) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void sortByGrade(Student* a[]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (a[j]->grade > a[j + 1]->grade) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void sortByBday(Student* a[]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            int julian1 = a[j]->bday.Greg2Julian(a[j]->bday.getMonth(), a[j]->bday.getDay(), a[j]->bday.getYear());
            int julian2 = a[j + 1]->bday.Greg2Julian(a[j + 1]->bday.getMonth(), a[j + 1]->bday.getDay(), a[j + 1]->bday.getYear());

            if (julian1 > julian2) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void sortByHometown(Student* a[]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (a[j]->homeTown > a[j + 1]->homeTown) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}