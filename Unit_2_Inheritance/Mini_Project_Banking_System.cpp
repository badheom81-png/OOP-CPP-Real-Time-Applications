#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Account {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int number, string name, double initialBalance)
        : accountNumber(number), holderName(name), balance(initialBalance) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    virtual bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    virtual double calculateInterest() const = 0;

    virtual void display() const {
        cout << "Account No: " << accountNumber
             << " | Holder: " << holderName
             << " | Balance: Rs. " << fixed << setprecision(2)
             << balance << endl;
    }

    virtual ~Account() = default;
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int number, string name, double initialBalance,
                    double rate)
        : Account(number, name, initialBalance),
          interestRate(rate) {}

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "Savings Account | ";
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

class CurrentAccount : public Account {
private:
    double interestRate;

public:
    CurrentAccount(int number, string name, double initialBalance,
                   double rate)
        : Account(number, name, initialBalance),
          interestRate(rate) {}

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "Current Account | ";
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double interestRate;
    int durationYears;

public:
    FixedDepositAccount(int number, string name, double initialBalance,
                        double rate, int years)
        : Account(number, name, initialBalance),
          interestRate(rate), durationYears(years) {}

    double calculateInterest() const override {
        return balance * interestRate * durationYears / 100;
    }

    bool withdraw(double amount) override {
        cout << "Withdrawal is not allowed from Fixed Deposit Account "
             << "before maturity." << endl;
        return false;
    }

    void display() const override {
        cout << "Fixed Deposit Account | ";
        Account::display();
        cout << "Interest: Rs. " << calculateInterest()
             << " | Duration: " << durationYears << " years" << endl;
    }
};

int main() {
    vector<unique_ptr<Account>> accounts;

    accounts.push_back(
        make_unique<SavingsAccount>(
            1001, "Rahul", 50000, 4.0
        )
    );

    accounts.push_back(
        make_unique<CurrentAccount>(
            1002, "Priya", 75000, 2.0
        )
    );

    accounts.push_back(
        make_unique<FixedDepositAccount>(
            1003, "Amit", 100000, 7.0, 2
        )
    );

    accounts[0]->deposit(5000);
    accounts[1]->withdraw(10000);
    accounts[2]->withdraw(5000);

    cout << "=== Banking System ===" << endl;

    for (const auto& account : accounts) {
        account->display();
        cout << endl;
    }

    return 0;
}