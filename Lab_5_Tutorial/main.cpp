#include <iostream>
#include "BankAccount.h"

using namespace std;

int main(){

    BankAccount daveAcc;
    BankAccount cindyAcc("Cindy");
    BankAccount billAcc("Bill", 123456, 2000);

    daveAcc.printSummary();
    cindyAcc.printSummary();
    billAcc.printSummary();

    billAcc.withdraw(500);
    billAcc.withdraw(2500);

    cout << "\nBill's balance: " << billAcc.getBalance() << endl;

    billAcc.deposit(1250);

    cout << "Bill's balance: " << billAcc.getBalance() << endl;
}


