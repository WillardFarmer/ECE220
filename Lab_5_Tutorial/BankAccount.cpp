#include <iostream>
#include <cstring>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount(){
    name[0] = 0;
    account_number = 0;
    balance = 0;
}
BankAccount::BankAccount(const char * self_name) {
    strcpy(name, self_name);
    account_number = 0;
    balance = 0;
}
BankAccount::BankAccount(const char * self_name, int self_account_number, double self_balance){
    strcpy(name, self_name);
    account_number = self_account_number;
    balance = self_balance;
}

void BankAccount::printSummary() {
    cout<< "\nName: " << name << endl;
    cout<< "Account Number: " << account_number << endl;
    cout<< "Balance: " << balance << endl;
}
void BankAccount::change_name(char * self_name) {
    strcpy(name, self_name);
}
void BankAccount::change_account_number(int self_account_number) {
    account_number = self_account_number;
}
void BankAccount::change_balance(double self_balance){
    balance = self_balance;
}

void BankAccount::withdraw(double amount) {
    if(amount > balance){
        cout<< "Insufficient funds\n";
        return;
    }
    balance -= amount;
}
void BankAccount::deposit(double amount) {
    balance += amount;
}
double BankAccount::getBalance() {
    return balance;
}
