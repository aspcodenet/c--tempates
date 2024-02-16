 #include "student.h"


Student::Student(std::string name, std::string ort)
    :namn(name),ort(ort)
{
}

std::string Student::getName(){
    return namn;
};

std::string Student::getOrt(){
    return ort;
};
