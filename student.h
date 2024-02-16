#ifndef STUDENT_H 
#define STUDENT_H

#include <string>

class Student{
public:
    Student(std::string namn, std::string ort);
    std::string getName();
    std::string getOrt();
private:    
    std::string namn;
    //float balance;
    std::string ort;
    
};


#endif