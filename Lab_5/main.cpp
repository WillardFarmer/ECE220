#include <iostream>
#include <iomanip>
#include <cstring>
#define NAME_MAXL 30

using namespace std;


class BankAccount {
protected: //Protected so sub class can variables

    char name[ NAME_MAXL ]{};
    int account_number;
    double balance;

public:

    BankAccount();
    BankAccount(const char *);
    BankAccount(const char *, int, double);

    void print_Summary();
    void change_name(char *);
    void change_account_number(int);
    void change_balance(double);

    void bankwithdraw(double); //differentiate between sub-method withdraw and super method
    void deposit(double);
    double getBalance();
};

class saveBankAccount: public BankAccount {
private:

    int noWithDraws;
    int MAXnoWithDraws;
    double interestRate;

public:

    saveBankAccount(const char*, int, double, double, int);
    void printSummary();
    void resetWithdraws();
    void printBalance();   //Not required by the lab but methods are fun
    double callInterest();
    double withdraw(double);

};


//############
//## main() ##
//############


int main(){

    saveBankAccount tomAcc("Tom", 234567, 3000, 0.05, 1);
    tomAcc.printSummary();

    tomAcc.withdraw(500);
    tomAcc.withdraw(500);
    tomAcc.printBalance();

    tomAcc.resetWithdraws();
    tomAcc.withdraw(500);
    tomAcc.printBalance();

}


//#####################
//## Function Bodies ##
//#####################

//Tutorial Constructors
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

//Tutorial Methods
void BankAccount::print_Summary() {
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
void BankAccount::bankwithdraw(double amount) {
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


//Lab Constructor
saveBankAccount::saveBankAccount(const char * self_name,
                                 int self_account_number,
                                 double self_balance,
                                 double self_interestRate,
                                 int self_MAXnoWithDraws) {

    strcpy(name, self_name);
    account_number = self_account_number;
    balance = self_balance;
    interestRate = self_interestRate;
    MAXnoWithDraws = self_MAXnoWithDraws;
    noWithDraws = 0;
}

//Lab Methods
void saveBankAccount::printSummary() {
    BankAccount::print_Summary();
    cout << "Interest Rate: " << interestRate << endl;
    cout << "Number of Withdrawals: " << noWithDraws << endl;
    cout << "Maximum Number of Withdrawals: " << MAXnoWithDraws << endl << endl;
}
void saveBankAccount::resetWithdraws() {
    noWithDraws = 0;
}
void saveBankAccount::printBalance() {
    cout << fixed; //Needed to set the precision to 2 decimal points
    cout << name << "'s balance: $" << setprecision(2) << getBalance() << endl;
}
double saveBankAccount::callInterest() {
    return balance*interestRate;
}
double saveBankAccount::withdraw(double amount) {
    if(amount > balance){
        cout << "Insufficient funds.\n";
        return 0;
    }else if( noWithDraws == MAXnoWithDraws) {
        cout << "The maximum number of withdrawals has been reached\n";
        return 0;
    }
    noWithDraws++;
    balance -= amount;
    return amount;
}

