#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void sortItems(vector<T>& values) {
    for (size_t i = 0; i < values.size(); i++) {
        for (size_t j = i + 1; j < values.size(); j++) {
            if (values[j] < values[i]) {
                T temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

template <typename T>
void displayItems(const vector<T>& values) {
    for (const auto& value : values) {
        cout << value << " ";
    }

    cout << endl;
}

int main() {
    vector<int> ids{64, 34, 25, 12, 22, 11, 90};
    vector<double> scores{3.14, 2.71, 1.41, 9.99, 0.50};
    vector<string> cities{
        "Pune",
        "Mumbai",
        "Nashik",
        "Aurangabad"
    };

    cout << "Integer IDs before sorting: ";
    displayItems(ids);

    sortItems(ids);

    cout << "Integer IDs after sorting: ";
    displayItems(ids);

    cout << "Scores before sorting: ";
    displayItems(scores);

    sortItems(scores);

    cout << "Scores after sorting: ";
    displayItems(scores);

    cout << "Cities before sorting: ";
    displayItems(cities);

    sortItems(cities);

    cout << "Cities after sorting: ";
    displayItems(cities);

    return 0;
}