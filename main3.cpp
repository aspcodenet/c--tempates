#include <iostream>
#include <vector>
#include <string>

class Student{
public:
    std::string namn;
    //float balance;
    std::string ort;
};


// TID SNABBARE
// ORDO fortfarande SAMMA

void bubbleSort(std::vector<Student> &students){
    int antalSwappar = 0;
    int antalVarv = 0;
    do{
        antalSwappar = 0;
        for(int i = 0; i < students.size()-antalVarv-1;i++){
            std::cout << "Varv " << i << std::endl;
            for(auto s : students){
                std::cout << s.namn << std::endl;
            }
            // innan dess en if sats liksom!
            if(students[i].namn > students[i+1].namn){
                antalSwappar++;
                Student temp =  students[i];
                students[i] = students[i+1];
                students[i+1] = temp;
            }
        }
        antalVarv++;
    }while(antalSwappar > 0);
}


int main(){
    std::vector<Student> students;
    students.push_back(Student{"Stefan", "Stockholm"});
    students.push_back(Student{"Anna", "Stockholm"});
    students.push_back(Student{"Oliver", "Nacka"});
    students.push_back(Student{"Josefine", "Nacka"});
    students.push_back(Student{"Fanny", "Nacka"});

    bubbleSort(students);
    for(auto s : students){
        std::cout << s.namn << std::endl;
    }
    return 0;
}


