#include "BankAccountSystem.h"
#include <limits>
//Function for input Validation
void invalidInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


    //Prompts the user for account information
BankAccount BankAccount::createAccountFromInput () {
    std::string accNum;
    std::string holder;
    double bal;

    std::cout << "Enter Account Number: " << std::endl;
    std::getline(std::cin, accNum);

    std::cout << "Enter Account Holder Name: " << std::endl;
    std::getline(std::cin, holder);

    //Input validation for initial balance
    while (true) {
        std::cout << "Enter Initial Balance: " << std::endl;
        std::cin >> bal;
        if (std::cin.fail()) {
            invalidInput();
            std::cout << "Invalid Input, Please Enter A Number" << std::endl;
        }
        else if (bal <= 0) {
            std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    //Returns a new BankAccount objected from inputed data
    return BankAccount(accNum, holder, bal);
}

//Accessors
std::string BankAccount::GetAccountNumber() const {
    return accountNumber;
}
std::string BankAccount::GetHolderName() const {
    return holderName;
}
double BankAccount::GetBalance() const {
    return balance;
}