 #include "student.h"
#include <time.h>
#include <iostream>


Student::Student(std::string name, std::string ort, time_t datum)
    :namn(name),ort(ort),birthDate(datum)
{
}


void Student::printDate(){
    // skriv ut i 2022-01-30

    struct tm *timeInfo = localtime(&birthDate);
    std::cout << (timeInfo->tm_year +1900) << "-" << (timeInfo->tm_mon + 1) << "-" << timeInfo->tm_mday << std::endl   ;

};


time_t Student::getBirthDate(){
    return birthDate;
};


std::string Student::getName(){
    return namn;
};

std::string Student::getOrt(){
    return ort;
};
