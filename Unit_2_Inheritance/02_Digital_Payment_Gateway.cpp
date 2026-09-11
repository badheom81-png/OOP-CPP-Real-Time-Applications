#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class PaymentMethod {
protected:
    string transactionId;
    double amount;

public:
    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt) {}

    virtual bool processPayment() const = 0;
    virtual ~PaymentMethod() = default;
};

class CreditCardPayment : public PaymentMethod {
private:
    string maskedCardNumber;

public:
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt), maskedCardNumber(card) {}

    bool processPayment() const override {
        cout << "Credit-card transaction " << transactionId
             << " for Rs. " << amount
             << " using " << maskedCardNumber
             << " completed." << endl;
        return true;
    }
};

class UPIPayment : public PaymentMethod {
private:
    string upiId;

public:
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt), upiId(upi) {}

    bool processPayment() const override {
        cout << "UPI transaction " << transactionId
             << " for Rs. " << amount
             << " from " << upiId << " completed." << endl;
        return true;
    }
};

class NetBankingPayment : public PaymentMethod {
private:
    string bankName;

public:
    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt), bankName(bank) {}

    bool processPayment() const override {
        cout << "Net-banking transaction " << transactionId
             << " for Rs. " << amount
             << " through " << bankName << " completed." << endl;
        return true;
    }
};

int main() {
    vector<unique_ptr<PaymentMethod>> payments;

    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001", 2500, "XXXX-XXXX-1234"
        )
    );

    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002", 1200, "student@upi"
        )
    );

    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003", 5000, "Example Bank"
        )
    );

    cout << "=== Payment Gateway ===" << endl;

    for (const auto& payment : payments) {
        payment->processPayment();
    }

    return 0;
}