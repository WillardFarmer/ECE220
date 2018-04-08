#ifndef LAB_5_TUTORIAL_BANKACCOUNT_H
#define LAB_5_TUTORIAL_BANKACCOUNT_H
#endif

#define NAME_MAXL 30

class BankAccount {

private:

    char name[ NAME_MAXL ]{};
    int account_number;
    double balance;

public:

    BankAccount();
    BankAccount(const char *);
    BankAccount(const char *, int, double);

    void printSummary();
    void change_name(char *);
    void change_account_number(int);
    void change_balance(double);

    void withdraw(double);
    void deposit(double);
    double getBalance();
};
