#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "student.h"

// 1. Header-filer osv CPP
// 2. Datum time_t vs c++20  date  using namespace std::chrono; + using namespace date;
// 3. sortera på datum ...
// 4. Enum
// 5. GIT !!!

// TID SNABBARE
// ORDO fortfarande SAMMA

// PlayerPosition
// Goalie, Defence, Forward, Center, MidFielder
// målis

// int -2 -> +2 milj

typedef enum{ // uppräkning av ok värden
    Ascending,
    Descending 
} SORTING_ORDER;

void bubbleSort(std::vector<Student> &students, SORTING_ORDER sortOrder)
{
    int antalSwappar = 0;
    int antalVarv = 0;
    do
    {
        antalSwappar = 0;
        for (int i = 0; i < students.size() - antalVarv - 1; i++)
        {
            std::cout << "Varv " << i << std::endl;
            for (auto s : students)
            {
                std::cout << s.getName() << std::endl;
            }
            // innan dess en if sats liksom!
            // VI ÄNDRAR BARA DENNA RAD
            if(sortOrder == Ascending){
                if (students[i].getBirthDate() < students[i + 1].getBirthDate())
                {
                    antalSwappar++;
                    Student temp = students[i];
                    students[i] = students[i + 1];
                    students[i + 1] = temp;
                }
            }else{
                if (students[i].getBirthDate() > students[i + 1].getBirthDate())
                {
                    antalSwappar++;
                    Student temp = students[i];
                    students[i] = students[i + 1];
                    students[i + 1] = temp;
                }
            }
        }
        antalVarv++;
    } while (antalSwappar > 0);
}

// ASC
// i = 1
//    Hitta den som ska LIGGA PÅ POSITION i
//        loopa igenom och  hitta den minsta
//           swap index för den minsta och i

/*
0  Anna
1 Stefan
2 Oliver
3 Josefine
4 Fanny
*/

void selectionSort(std::vector<Student> &students)
{
    // YTTRE LOOPEN = en POSITION i taget - vem ska stoppas i på den positionen
    for (int i = 0; i < students.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < students.size() - 1; j++)
        {
            if (students[minIndex].getName() > students[j].getName())
            {
                minIndex = j;
            }
        }
        // Nu är minindex det MINSTA indexet = 3
        if (minIndex != i)
        {
            Student temp = students[minIndex];
            students[minIndex] = students[i];
            students[i] = temp;
        }
    }
}

time_t toTime(int year, int mon, int day ){
    struct tm tn{};
    tn.tm_year = year-1900;
    tn.tm_mon = mon-1;
    tn.tm_mday = day;
    return mktime(&tn);
}

int main()
{
    // using namespace std::chrono;
    // std::chrono::year_month_day datum( 2020y, std::chrono::January, 31d);

    // Datum d = Datum(1972,8,3);

    // https://en.cppreference.com/w/cpp/language/user_literal
    // time_t   https://www.softwaretestinghelp.com/date-and-time-in-cpp/

    time_t now;
    time ( &now );
    //struct tm *mytime = localtime(&now);

    std::vector<Student> students;
    students.push_back(Student("Stefan", "Stockholm", toTime(1972,8,3)));
    students.push_back(Student("Anna", "Stockholm", toTime(1970,11,4)));
    students.push_back(Student("Oliver", "Nacka", toTime(2008,5,28)));

    students[0].printDate();
    //std::cout << "Hur vill du sortera?" ;
    //std::string sortOrder = "asc";
    //std::cin >> sortOrder;
    bubbleSort(students, Descending);
    //selectionSort(students);
    for (auto s : students)
    {
        std::cout << s.getName() << std::endl;
    }
    return 0;
}
