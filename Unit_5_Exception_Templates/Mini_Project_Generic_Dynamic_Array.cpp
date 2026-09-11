#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int currentSize;

public:
    explicit DynamicArray(int size)
        : capacity(size), currentSize(0) {

        if (size <= 0) {
            throw invalid_argument(
                "Array capacity must be positive."
            );
        }

        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(const T& value) {
        if (currentSize == capacity) {
            throw overflow_error(
                "Array capacity exceeded."
            );
        }

        data[currentSize++] = value;
    }

    void remove(int index) {
        if (index < 0 || index >= currentSize) {
            throw out_of_range(
                "Invalid index for deletion."
            );
        }

        for (int i = index; i < currentSize - 1; i++) {
            data[i] = data[i + 1];
        }

        currentSize--;
    }

    T& at(int index) {
        if (index < 0 || index >= currentSize) {
            throw out_of_range(
                "Invalid array index."
            );
        }

        return data[index];
    }

    int size() const {
        return currentSize;
    }

    void display() const {
        for (int i = 0; i < currentSize; i++) {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    try {
        DynamicArray<int> numbers(5);

        numbers.insert(10);
        numbers.insert(20);
        numbers.insert(30);
        numbers.insert(40);

        cout << "Array elements: ";
        numbers.display();

        cout << "Element at index 2: "
             << numbers.at(2) << endl;

        numbers.remove(1);

        cout << "After deletion: ";
        numbers.display();

        cout << "Current size: "
             << numbers.size() << endl;

        DynamicArray<string> names(3);

        names.insert("Rahul");
        names.insert("Priya");
        names.insert("Amit");

        cout << "String array: ";
        names.display();
    }
    catch (const exception& error) {
        cout << "Error: " << error.what() << endl;
    }

    return 0;
}