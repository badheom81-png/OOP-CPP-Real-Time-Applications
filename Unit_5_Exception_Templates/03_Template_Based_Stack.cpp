#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex;

public:
    explicit Stack(int size)
        : capacity(size), topIndex(-1) {

        if (size <= 0) {
            throw invalid_argument(
                "Stack capacity must be positive."
            );
        }

        data = new T[capacity];
    }

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) {
        if (topIndex == capacity - 1) {
            throw overflow_error("Stack overflow.");
        }

        data[++topIndex] = value;
    }

    T pop() {
        if (topIndex < 0) {
            throw underflow_error("Stack underflow.");
        }

        return data[topIndex--];
    }

    bool isEmpty() const {
        return topIndex < 0;
    }

    void display() const {
        for (int i = topIndex; i >= 0; i--) {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    try {
        Stack<int> integerStack(5);

        integerStack.push(10);
        integerStack.push(20);
        integerStack.push(30);

        cout << "Integer stack: ";
        integerStack.display();

        cout << "Popped: "
             << integerStack.pop() << endl;

        Stack<string> commandStack(3);

        commandStack.push("Open file");
        commandStack.push("Edit text");
        commandStack.push("Save file");

        cout << "Command stack: ";
        commandStack.display();
    }
    catch (const exception& error) {
        cout << "Error: " << error.what() << endl;
    }

    return 0;
}