#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

class InputValidator {
public:
    template <typename T>
    bool validate(T value) const {
        return validateValue(value);
    }

private:
    bool validateValue(int value) const {
        return value >= 0 && value <= 100;
    }

    bool validateValue(double value) const {
        return value >= 0.0;
    }

    bool validateValue(const string& value) const {
        if (value.empty()) {
            return false;
        }

        for (char ch : value) {
            if (!isalpha(ch) && ch != ' ') {
                return false;
            }
        }

        return true;
    }
};

int main() {
    InputValidator validator;

    cout << "Marks 88 valid: "
         << validator.validate(88) << endl;

    cout << "Marks 120 valid: "
         << validator.validate(120) << endl;

    cout << "Amount 4500.50 valid: "
         << validator.validate(4500.50) << endl;

    cout << "Name Priya Sharma valid: "
         << validator.validate(string("Priya Sharma")) << endl;

    cout << "Name Priya123 valid: "
         << validator.validate(string("Priya123")) << endl;

    return 0;
}