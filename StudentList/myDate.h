#include <stdio.h>
#include <string>
#ifndef H_date
#define H_date 
using namespace std;

class myDate
{
private:
    int year, month, day;
    char character;
    string months[12]{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    string days[7]{ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
public:
    int Greg2Julian(int month, int day, int year);
    void Julian2Greg(int JD, int& month, int& day, int& year);
    myDate();
    myDate(int M, int D, int Y);
    void display();
    void increaseDate(int N);
    void decreaseDate(int N);
    int daysBetween(myDate D);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
    string monthName();
    char getchar();
    string toString();
};

#endif
