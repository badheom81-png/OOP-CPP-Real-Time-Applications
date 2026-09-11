#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct LogEntry {
    string line;
};

int main() {
    ofstream sampleLog("server.log");

    if (!sampleLog) {
        cerr << "Unable to create log file." << endl;
        return 1;
    }

    sampleLog << "2026-09-09 08:00:00 INFO Server started\n";
    sampleLog << "2026-09-09 08:10:00 WARNING High memory usage\n";
    sampleLog << "2026-09-09 08:20:00 ERROR Database connection failed\n";
    sampleLog << "2026-09-09 08:30:00 INFO Backup completed\n";
    sampleLog << "2026-09-09 08:40:00 CRITICAL Disk space low\n";

    sampleLog.close();

    ifstream logFile("server.log");

    if (!logFile) {
        cerr << "Unable to open server.log." << endl;
        return 1;
    }

    vector<LogEntry> errors;
    string line;

    while (getline(logFile, line)) {
        if (line.find("ERROR") != string::npos ||
            line.find("CRITICAL") != string::npos) {
            errors.push_back({line});
        }
    }

    cout << "=== Critical Log Events ===" << endl;

    for (const auto& entry : errors) {
        cout << entry.line << endl;
    }

    cout << "Total critical events: "
         << errors.size() << endl;

    return 0;
}