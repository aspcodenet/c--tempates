#ifndef STUDENT_H 
#define STUDENT_H

#include <string>

class Student{
public:
    Student(std::string namn, std::string ort, time_t datum);
    std::string getName();
    std::string getOrt();
    time_t getBirthDate(); 
    void printDate(); // 2002-03-30
private:    
    std::string namn;
    //float balance;
    std::string ort;
    time_t birthDate;
};


#endif