#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0)
        : real(r), imaginary(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(
            real + other.real,
            imaginary + other.imaginary
        );
    }

    Complex operator-(const Complex& other) const {
        return Complex(
            real - other.real,
            imaginary - other.imaginary
        );
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real
        );
    }

    void display() const {
        cout << real;

        if (imaginary >= 0)
            cout << " + " << imaginary << "i";
        else
            cout << " - " << -imaginary << "i";

        cout << endl;
    }
};

int main() {
    Complex c1(4, 3);
    Complex c2(2, 1);

    cout << "=== Complex Number Calculator ===" << endl;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    difference.display();

    cout << "Multiplication: ";
    product.display();

    return 0;
}