#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct LogEntry {
    string ip;
    string request;
};

int main() {
    vector<LogEntry> logs{
        {"192.168.1.1", "GET /index.html"},
        {"192.168.1.2", "POST /api/data"},
        {"192.168.1.1", "GET /about.html"},
        {"192.168.1.3", "GET /contact.html"},
        {"192.168.1.1", "GET /products.html"},
        {"192.168.1.2", "GET /api/users"},
        {"192.168.1.1", "POST /api/order"},
        {"192.168.1.4", "GET /index.html"},
        {"192.168.1.1", "GET /services.html"},
        {"192.168.1.2", "GET /api/products"}
    };

    map<string, int> requestCount;

    for (const auto& entry : logs) {
        requestCount[entry.ip]++;
    }

    vector<pair<string, int>> ranked(
        requestCount.begin(),
        requestCount.end()
    );

    sort(ranked.begin(), ranked.end(),
         [](const auto& first, const auto& second) {
             return first.second > second.second;
         });

    cout << "=== Request Count by IP Address ===" << endl;

    for (const auto& item : ranked) {
        cout << item.first
             << " : " << item.second
             << " requests" << endl;
    }

    return 0;
}