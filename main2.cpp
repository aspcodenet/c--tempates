#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>

//using namespace std;

class BankAccount{
    std::string accountNumber;
    float balance;
public:
    BankAccount(){

    }
    BankAccount(std::string accountNumber, float balance = 0)
    :accountNumber(accountNumber),balance(balance)
    {
    }

    std::string getAccountNumber()
    {
	    return this->accountNumber;
    }
};

class IAccountStorage {
public:    
    virtual void addAccount(BankAccount account) = 0;
	virtual BankAccount *findAccount(std::string accountNumber) = 0;        
};



class Bank
{
private:
	IAccountStorage * accountStorage;
public:
	Bank(IAccountStorage *storage):accountStorage(storage){

    }
	bool addAccount(std::string accountNumber){
        //validate
        //if something (accountNumber) return false
        accountStorage->addAccount(accountNumber);
        return true;
    }
	BankAccount *getAccount(std::string accountNumber){
        return accountStorage->findAccount(accountNumber);
    }
};

// ORDO = om vi lägger till x till saker - hur mycket långsammare blir algoritmen


// Du om du använder min algo - n^2

//   10  50 sek
//   100  2500


// Om 10 st    - 5 accesser
// Öka med 10 000 - 5 000 accesser


// VectorAccountStorage = O(n)

class VectorAccountStorage: public IAccountStorage{
        std::vector<BankAccount> accounts;
public:
    void addAccount(BankAccount account) override{
        accounts.push_back(account);
    }

    BankAccount *findAccount(std::string accountNumber){
        //for(BankAccount &account : accounts){
        for(int i = 0; i < accounts.size();i++){
            BankAccount &account = accounts[i];
            if(account.getAccountNumber() == accountNumber ){
                return &account;                                        
            }
        }
        return nullptr;
    }
    

};   // 10 miljoner 100ms   O(n)

class VectorAccountStorage2: public IAccountStorage{
        std::vector<BankAccount> accounts;
public:
    void addAccount(BankAccount account) override{
        accounts.push_back(account);
    }

    BankAccount *findAccount(std::string accountNumber){
        //for(BankAccount &account : accounts){
        for(int i = 0; i < accounts.size();i++){

            std::sleep_for(std::seconds(30));            //sleep(30 sekunder);
            BankAccount &account = accounts[i];
            if(account.getAccountNumber() == accountNumber ){
                return &account;                                        
            }
        }
        return nullptr;
    }
    

};  // 10 miljoner 1000 timmar   O(n)



// MAP BinarySearch
// 10 000 000 - 22 accesser 
// 20 000 000 - 23 accesser


class MapAccountStorage: public IAccountStorage{
        std::map<std::string,BankAccount> accounts;
public:
    void addAccount(BankAccount account) override{
        accounts[account.getAccountNumber()] = account;
    }

    BankAccount *findAccount(std::string accountNumber){
        return &accounts[accountNumber];
    }
    

};





int main(int, char**){

    //std::map<std::string,BankAccount> personerna;
    //personerna["2008-05-28"] = new BankAccount();

    int arrayen[10000000];  
    arrayen[0] = 12;  // o(1)
    arrayen[3] = 13; 
    arrayen[4] = 11; 

    // Array på index =  ordo(1)
    // oavsett storlek alltid samma tid att ta fram en specifik
    std::cout << arrayen[3]; // o(1)   // 550011 + 3 * sizeof(int)
    std::cout << arrayen[9]; // o(1)  // 550011 + 9 * sizeof(int)


    //VectorAccountStorage storage;
    MapAccountStorage storage;
    Bank bank(&storage);

    const int AntalAccounts =  1000000;


    std::string sFirst = ""; 
    std::string sLast = ""; 
    std::string sNotFound = "notfound"; 
    std::cout << "INITIALIZE: " << std::endl;
    
    // auto - är BEST PRACTICE
    //int i = 12;
//    auto i = 12;
//    auto player = new std::chrono::high_resolution_clock::HpckeyPlayer();
    auto startTime = std::chrono::high_resolution_clock::now();
//    std::chrono::_V2::system_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    for(int i = 0;i < AntalAccounts; i++){
        std::string accountNumber =  std::to_string(i);
        if(i == 0){
            sFirst = accountNumber;
        }
        if(i == AntalAccounts-1){
            sLast = accountNumber;
        }
        bank.addAccount(std::to_string(i));
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cout << "INIT Took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime    - startTime).count() << " milliseconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    BankAccount *p = bank.getAccount(sFirst);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << p->getAccountNumber() << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime    - startTime).count() << " milliseconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    p = bank.getAccount(sLast);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << p->getAccountNumber() << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime    - startTime).count() << " milliseconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    p = bank.getAccount(sNotFound);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "NOT FOUND" << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime    - startTime).count() << " milliseconds" << std::endl;
}