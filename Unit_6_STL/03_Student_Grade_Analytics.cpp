#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
    vector<double> marks{
        85.5, 92.0, 78.5, 88.0,
        95.5, 72.0, 89.5, 91.0
    };

    double total = accumulate(
        marks.begin(),
        marks.end(),
        0.0
    );

    double average = total / marks.size();

    cout << "Average: " << average << endl;

    cout << "Minimum: "
         << *min_element(marks.begin(), marks.end())
         << endl;

    cout << "Maximum: "
         << *max_element(marks.begin(), marks.end())
         << endl;

    sort(marks.begin(), marks.end());

    cout << "\nMarks in ascending order: ";

    for (double mark : marks) {
        cout << mark << " ";
    }

    cout << endl;

    priority_queue<double> topPerformers(
        marks.begin(),
        marks.end()
    );

    cout << "\nTop three marks:" << endl;

    for (int i = 0;
         i < 3 && !topPerformers.empty();
         i++) {

        cout << topPerformers.top() << endl;
        topPerformers.pop();
    }

    set<double> uniqueMarks(
        marks.begin(),
        marks.end()
    );

    cout << "\nUnique marks: ";

    for (double mark : uniqueMarks) {
        cout << mark << " ";
    }

    cout << endl;

    map<char, int> gradeDistribution;

    for (double mark : marks) {
        if (mark >= 90)
            gradeDistribution['A']++;
        else if (mark >= 80)
            gradeDistribution['B']++;
        else if (mark >= 70)
            gradeDistribution['C']++;
        else
            gradeDistribution['D']++;
    }

    cout << "\nGrade distribution:" << endl;

    for (const auto& item : gradeDistribution) {
        cout << "Grade " << item.first
             << ": " << item.second
             << " student(s)" << endl;
    }

    return 0;
}