#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class InsufficientFundsException : public exception {
private:
    double balance;
    double requestedAmount;

public:
    InsufficientFundsException(double currentBalance, double requested)
        : balance(currentBalance), requestedAmount(requested) {}

    const char* what() const noexcept override {
        return "Insufficient balance for withdrawal.";
    }

    double getBalance() const {
        return balance;
    }

    double getRequestedAmount() const {
        return requestedAmount;
    }
};

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    BankAccount(int number, string name, double openingBalance)
        : accountNumber(number),
          holderName(name),
          balance(openingBalance) {
        if (openingBalance < 0.0) {
            throw invalid_argument("Opening balance cannot be negative.");
        }
    }

    void deposit(double amount) {
        if (amount <= 0.0) {
            throw invalid_argument("Deposit amount must be positive.");
        }

        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0.0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }

        if (amount > balance) {
            throw InsufficientFundsException(balance, amount);
        }

        balance -= amount;
    }

    void display() const {
        cout << "Account: " << accountNumber
             << " | Holder: " << holderName
             << " | Balance: Rs. " << balance << endl;
    }
};

int main() {
    try {
        BankAccount account(1001, "Rahul", 5000.0);

        account.deposit(2000.0);
        account.withdraw(1500.0);

        account.display();

        account.withdraw(10000.0);
    }
    catch (const InsufficientFundsException& error) {
        cout << "Transaction failed: " << error.what() << endl;
        cout << "Available balance: Rs. "
             << error.getBalance() << endl;
        cout << "Requested amount: Rs. "
             << error.getRequestedAmount() << endl;
    }
    catch (const exception& error) {
        cout << "System error: " << error.what() << endl;
    }

    return 0;
}