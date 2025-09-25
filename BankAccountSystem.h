
#ifndef BANKMANAGEMENTSYSTEM_BANKACCOUNTSYSTEM_H
#define BANKMANAGEMENTSYSTEM_BANKACCOUNTSYSTEM_H


#include <string>
#include <iostream>


void invalidInput(); //for input validation

class BankAccount {
    public:
    BankAccount() {
        accountNumber = "0";
        holderName = "Default";
        balance = 0.0;
    }
    //parameterized Constructor
    BankAccount(std::string accNum, std::string holder, double bal) {
        accountNumber = accNum;
        holderName = holder;
        balance = bal;
    }
    // Copy Constructor
    //Ensures deep copy of all member variables
    BankAccount(const BankAccount& other) {
        accountNumber = other.accountNumber;
        holderName = other.holderName;
        balance = other.balance;
    }
    //Copy Assignment Operator
    //Assigns one BankAccount object to another
    BankAccount& operator=(const BankAccount& other) {
        accountNumber = other.accountNumber;
        holderName = other.holderName;
        balance = other.balance;
        return *this;
    }
    //Destructor
    virtual ~BankAccount() {
    }

    //Operator overload: +=
    //Adds money to the balance (used for deposits)
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance = balance + amount;
            std::cout << "Deposit Was Successful. \nUpdated Balance: $" << balance << std::endl;
        }
        else {
            std::cout << "Invalid Deposit Amount" << std::endl;
        }
    }

    //-Operator overload: -=
    //Subtracts money from the balance (used for withdrawals)
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance = balance - amount;
            std::cout << "Withdrawal Was Successful. \nUpdated Balance: $" << balance << std::endl;
        }
        else {
            std::cout <<"Withdrawal Failed. Insufficient Funds" << std::endl;
        }
    }

    //-Comparison Operators
    //If account numbers are the same, return true. Otherwise, return false
    bool operator==(const BankAccount &other) const {
        return accountNumber == other.accountNumber;
    }
    //If first selected account is less than second selected account, return true. Otherwise, return false
    bool operator<(const BankAccount &other) const {
        return balance < other.balance;
    }
    //If first selected account is greater than second selected account, return true. Otherwise, return false
    bool operator>(const BankAccount &other) const {
        return balance > other.balance;
    }

//Static Utility Functions
    //Prints account details
    static void printAccount(const BankAccount &account) {
        std::cout << "Account Number: " << account.accountNumber << std::endl;
        std::cout << "Holder Name: " << account.holderName << std::endl;
        std::cout << "Balance: $" << account.balance << std::endl;
    }
    static BankAccount createAccountFromInput();




    //Accessor(getters)
    std::string GetAccountNumber() const;
    std::string GetHolderName() const;
    double GetBalance() const;


private:
    //Variables
    std::string accountNumber;
    std::string holderName;
    double balance;
};


class CheckingAccount : public BankAccount {
public:
    CheckingAccount(std::string accNum, std::string holder, double bal) : BankAccount(accNum, holder, bal) {}

    void withdraw(double amount) override {
        double total;
        total = amount + transactionFee;
        if (total <= GetBalance()) {
            BankAccount::withdraw(total);
            std::cout << "Withdrawal Was Successful. Note: Transaction Fee of $ " << transactionFee << " applied." << std::endl;
        }
        else {
            std::cout << "Withdrawal Failed. Insufficient Funds" << std::endl;
        }
    }
private:
    double transactionFee = 1.50;
};




class SavingAccount : public BankAccount {
public:
    SavingAccount(std::string accNum, std::string holder, double bal) : BankAccount(accNum, holder, bal) {}

    void deposit(double amount) override {
        BankAccount::deposit(amount);
        calculateInterest();
    }


    void calculateInterest() {
        double interest;
        interest = GetBalance() * interestRate;
        std::cout << "Adding interest to your balance..." << std::endl;

        BankAccount::deposit(interest);
        std::cout << "Interest of $ " << interest <<  " was added to your account" << std::endl;

    }
private:
    double interestRate = 0.01;
};








#endif