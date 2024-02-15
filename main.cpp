#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "coolfunctions.h"


// DEFINE = preprocessorn - FATTAR INTE C/C++ ren TEXT



// DATASTRUKTURER = hur kan man skapa DS som funkar med "vad som helst" int, HockeyPlayer
// ALGORITMER - hur kan man återanvända en algoritm med "vad som helst" int, float, string

// C++ FUNCTION OVERLOADS 
// skiljer sig på dess SIGNATUR
//  return typ + parametertyper


// om T skulle betyda "int" så int findBiggest(int i, int j, int k)
// om T skulle betyda "float" så float findBiggest(float i, float j, float k)
template<typename T>
T findBiggest(T i, T j, T k){
    if(i > j && i > k){
        return i;
    }
    if(j > i && j > k){
        return j;
    }
    return k; //fhdsklfsdh
}



// int findBiggest(int i, int j, int k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k;
// }

// double findBiggest(double i, double j, double k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k;
// }


// float findBiggest(float i, float j, float k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k; //
// }

// std::string findBiggest(std::string i, std::string j, std::string k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k; //
// }


template <typename T>
void swap(T &i, T &j) {
    T temp = i;
    i = j;
    j  = temp;  
}



class Player{
public:    
    std::string Name;
    int Age;

};




// std::vector<>
// STL - standard template library
//template<class T,int N>
template<typename T,int N>
class MyArray{
public: 
    MyArray(){
        antal = 0;
    }
    void add(T one){
        // om antalet > max 
        // return "ERROR - finns inte plats för mer"
        // 
        things[antal] = one;
        antal++;
    }

    // void removeAt(int index){
    //     // foppa    kalle   stefan   lisa   anna   
    //     //  0        1          2       3    4         antal = 5
    //     // foppa    stefan     lisa    anna            antal = 4
    //  }




    int size(){
        return antal;
    }
    T getAt(int index){
        return things[index];
    }


private:
    int antal;
    T things[N]; // KAN INTE VÄXA/KRYMPA .- statisk i storlek  , INTE static
};


//EXERCISE 2:
//Skriv en funktion som hittar MINSTA värdet i en array !
template<typename T>
T findSmallest(std::vector<T> arrayen){
    T smallest = arrayen[0];
    for(int i = 0; i < arrayen.size();i++ ){
        if(arrayen[i] < smallest ){ // STEFAN SKA PRATA
            smallest = arrayen[i];
        }
    }
    return smallest;
    //loopa och ta frtam minsta
    // returnera
    // TEMPLATED
}
int main(){    
    int s = test(23,18); 
    // push 23 (4 bytes)
    // push 18 (4 bytes)
    // jmp in i funktionen()
    // ta pull 4 st bytes -> s

    std::vector<int> arr = {
        12,12,45543,234,3,342
    };
    int smallest = findSmallest(arr);


    std::vector<float> arr2 = {
        12.3f,12.342f,45543.342f,234.1f,3.0f,342.1223f
    };
    auto smallest2 = findSmallest(arr2);


    // static
    //std::vctor<int> INTE på embedded
    // aldrig malloc/free på embedded - 
    // STACKALLOKERADE DATASTRUKTURER
    Player foppa;
    foppa.Age = 52;
    foppa.Name = "Peter";

    MyArray<Player,1> team; 
    team.add(foppa);

    Player mats;
    mats.Age = 53;
    mats.Name = "Mats";
    team.add(mats);

    for(int i = 0; i < team.size(); i++){
        Player p = team.getAt(i);
        std::cout << p.Name << std::endl;
    }

    //team.removeAt(0);



    // MyArray<int,10> array; //10
    // MyArray<int,20> arrayPlayers; //20
    // MyArray<float,10> array2; //


    int tal1 = 12;
    int tal2 = 13;
    swap<int>(tal1,tal2);
    std::cout << "Tal1:" <<  tal1 << " Tal2:" <<tal2 << std::endl;

    float tal1f = 12.11f;
    float tal2f = 13.11f;
    swap<float>(tal1f,tal2f);
    std::cout << "Tal1:" <<  tal1f << " Tal2:" <<tal2f << std::endl;



    // int r,
    // int s;
    // test(r,s);
    //skapa en SWAP-metod skicka a och b och när man kommer tillbaka är värdena flyttade 
    // int v1 =12;
    // int v2 = 13;
    // swap<int>(v1,v2);
    // std::cout << v1 << v2 << std::endl; // 13, 12
    // float v1 =12;
    // float v2 = 13;
    // swap<float>(v1,v2);
    // std::cout << v1 << v2 << std::endl; // 13, 12
    


    // MyClass<int> 
    // MyClass<float> 
    int i = 11;
    int j = 12;
    int k = 13;

    int b = findBiggest<int>(i,j,k);
    //int b = findBiggest(i,j,k);
    std::cout << b << std::endl;


    std::string namn1 = "Anna";
    std::string namn2 = "Bertil";    
    std::string namn3 = "Carl";

    std::string bigg = findBiggest<std::string>(namn1,namn2,namn3);
    std::cout << bigg << std::endl;


    float i2 = 11.44f;
    float j2 = 12.11f;
    float k2 = 13.44f;

    float b2 = findBiggest<float>(i2,j2,k2);
    std::cout << b2 << std::endl;



}
