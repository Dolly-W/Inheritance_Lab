//Program for Bank Management System
//Inheritance Lab
//Dolly Warren
//MCSCI-272
//September 24th 2025

#include "BankAccountSystem.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

int main () {
    std::vector<BankAccount*> accounts; //Stores all bank accounts
    int choice;

    do {
        //Menu Options
        std::cout << "~~Welcome to the Bank Management System~~" << std::endl;
        std::cout << "1) Create an Account" << std::endl;
        std::cout << "2) Deposit Money" << std::endl;
        std::cout << "3) Withdrawal Money" << std::endl;
        std::cout << "4) Display all Accounts" << std::endl;
        std::cout << "5) Compare Accounts" << std::endl;
        std::cout << "6) Exit" << std::endl;

        while (true) {
            std::cout << "Enter Choice: ";
            std::cin >> choice;
            //Input Validation if user inputs letters
            if (std::cin.fail()) {
                invalidInput();
                std::cout << "Invalid Input, Please Enter A Number" << std::endl;
            }
            //Input Validation if input number less than 1
            else if (choice < 1 || choice > 6) {
                invalidInput();
                std::cout << "Invalid Input, Please Enter A Number Between 1-6" << std::endl;
            }
            else {
                //clear input
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        switch (choice) {
            case 1: {
                int choice;
                while (true) {
                    std::cout << "Select Account Type: " << std::endl;
                    std::cout << "1) Checking Account" << std::endl;
                    std::cout << "2) Savings Account" << std::endl;
                    std::cin >> choice;
                    if (std::cin.fail() || choice != 1 && choice != 2) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter 1 or 2" << std::endl;
                        continue;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                BankAccount base = BankAccount::createAccountFromInput();

                if (choice ==1) {

                    accounts.push_back(new CheckingAccount(base.GetAccountNumber(), base.GetHolderName(), base.GetBalance()));
                    std::cout << "Checking Account Has Been Successfully Created. Note: Transaction Fee: $1.50" <<  std::endl;
                }
                else if (choice == 2) {

                    accounts.push_back(new SavingAccount(base.GetAccountNumber(), base.GetHolderName(), base.GetBalance()));
                    std::cout << "Savings Account Has Been Successfully Created. Note: Interest Rate: 1%" <<  std::endl;
                }
                else {
                    invalidInput();
                    std::cout << "Invalid Input, Please Enter A Number Between 1-2" << std::endl;
                }
                break;
            }
            case 2: {
                //If no accounts exist
                if (accounts.empty()) {
                    std::cout << "No Accounts Exist Yet, Please Create One" << std::endl;
                    break;
                }
                int accountChoice;
                while (true) {
                    std::cout << "Select An Account: " << std::endl;
                    for (int i = 0; i < accounts.size(); i++) {
                        std::cout << i + 1 << ") " << accounts[i]->GetAccountNumber() << " - " << accounts[i]->GetHolderName() << std::endl;
                    }
                    std::cout << "Enter Choice: " << std::endl;
                    std::cin >> accountChoice;
                    //Input validation if user inputs letters
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    //Input Validation if user inputs number less than 1
                    else if (accountChoice < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
                    }
                    //Input validation if user inputs number outside of scope
                    else if (accountChoice > accounts.size()) {
                        invalidInput();
                        std::cout << "Invalid Input, Account Doesn't Exist" << std::endl;
                    }
                    else {
                        //clear input
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                double amount;
                while (true) {
                    std::cout << "Enter Deposit Amount: " << std::endl;
                    std::cin >> amount;
                    //input validation if user inputs letters
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    //input validation if user inputs number less than 1
                    else if (amount <= 0) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter An Amount Greater Than 0" << std::endl;
                    }
                    else {
                        //clear input
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                //Adds deposit amount into selected account
                accounts[accountChoice - 1]->deposit(amount);
                break;
            }
            case 3: {
                //Input validation if no accounts have been created
                if (accounts.empty()) {
                    std::cout << "No Accounts Exist Yet, Please Create One" << std::endl;
                    break;
                }
                int accountChoice;
                while (true) {
                    std::cout << "Select An Account: " << std::endl;
                    for (int i = 0; i < accounts.size(); i++) {
                        std::cout << i + 1 << ") " << accounts[i]->GetAccountNumber() << " - " << accounts[i]->GetHolderName() << std::endl;
                    }
                    std::cout << "Enter Choice: " << std::endl;
                    std::cin >> accountChoice;
                    //Inputs validation if user inputs letters
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    //Input validation if user inputs number less than 1
                    else if (accountChoice < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
                    }
                    //Input Validation if user inputs number outside of scope
                    else if (accountChoice > accounts.size()) {
                        invalidInput();
                        std::cout << "Invalid Input, Account Doesn't Exist" << std::endl;
                    }
                    else {
                        //clear input
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                double amount;
                while (true) {
                    std::cout << "Enter Withdrawal Amount: " << std::endl;
                    std::cin >> amount;
                    //input validation if user inputs letters
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    //input validation if user inputs number less than 1
                    else if (amount < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter An Amount Greater than 0" << std::endl;
                    }
                    else {
                        //clear input
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                //removes withdrawal amount from selected account
                accounts[accountChoice - 1]->withdraw(amount);
                break;
            }
            case 4: {
                //Input validation if no account has been created
                if (accounts.empty()) {
                    std::cout << "No Accounts Exist Yet, Please Create One" << std::endl;
                    break;
                }
                //display all accounts
                for (int i = 0; i < accounts.size(); i++) {
                    BankAccount::printAccount(*accounts[i]);
                }
                break;
            }
            case 5: {//Compares two accounts
                if (accounts.empty()) {
                    std::cout << "No Accounts Exist Yet, Please Create One" << std::endl;
                    break;
                }
                if (accounts.size() < 2) {
                    std::cout << "Need At Least Two Accounts To Compare" << std::endl;
                    break;
                }

                int acc1;
                int acc2;

                while (true) {
                    //First account selection
                    std::cout << "Select First Account: " << std::endl;
                    for (int i = 0; i < accounts.size(); i++) {
                        std::cout << i + 1 << ") " << accounts[i]->GetAccountNumber() << " - " << accounts[i]->GetHolderName() << std::endl;
                    }
                    std::cin >> acc1;

                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    else if (acc1 < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
                    }
                    else if (acc1 > accounts.size()) {
                        invalidInput();
                        std::cout << "Invalid Input, Account Doesn't Exist" << std::endl;
                    }
                    else {
                        break;
                    }
                }
                while (true) {
                    //Second account selection
                    std::cout << "Select Second Account: " << std::endl;
                    for (int i = 0; i < accounts.size(); i++) {
                        std::cout << i + 1 << ") " << accounts[i]->GetAccountNumber() << " - " << accounts[i]->GetHolderName() << std::endl;
                    }
                    std::cin >> acc2;
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    else if (acc2 < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
                    }
                    else if (acc2 > accounts.size()) {
                        invalidInput();
                        std::cout << "Invalid Input, Account Doesn't Exist" << std::endl;
                    }
                    else {
                        break;
                    }
                }
                //-Overload operators to compare accounts
                //If account numbers are the name
                if (*accounts[acc1 -1] == *accounts[acc2 - 1]) {
                    std:: cout << "Account " << acc1 << " and " << acc2 << " have the same account number" << std::endl;
                }
                else {
                    //If account numbers are different
                    std::cout << "Account " << acc1 << " and " << acc2 << " have different account numbers" << std::endl;
                }
                //If first selected account has lower balance than second selected account
                if (*accounts[acc1 - 1] < *accounts[acc2 - 1]) {
                    std::cout << "Account " << acc1 << " has a lower balance than Account " << acc2 << std::endl;
                }
                //If first selected account has greater balance than second account
                else if (*accounts[acc1 - 1] > *accounts[acc2 - 1]) {
                    std::cout << "Account " << acc1 << " has a higher balance than Account " << acc2 << std::endl;
                }
                else {
                    //If both selected accounts have same balance
                    std::cout << "Both accounts have the same balance" << std::endl;
                }
                break;
            }
            case 6:
                std::cout << "Exiting Program..." << std::endl;
                break;
            default:
                std::cout << "Invalid Input, Please Try Again" << std::endl;
        }
    }
    while (choice != 6);
    return 0;
}