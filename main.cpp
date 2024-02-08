#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

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



// void test(int &i, int &j) {
//     i++;
// }



int main(){
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
