#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SmartDevice {
private:
    string deviceId;
    string location;
    string status;
    string lastUpdated;

public:
    SmartDevice(string id, string loc, string initialStatus, string time)
        : deviceId(id), location(loc),
          status(initialStatus), lastUpdated(time) {}

    void switchOn(string time) {
        status = "ON";
        lastUpdated = time;
    }

    void switchOff(string time) {
        status = "OFF";
        lastUpdated = time;
    }

    void changeStatus(string newStatus, string time) {
        status = newStatus;
        lastUpdated = time;
    }

    void display() const {
        cout << "Device ID: " << deviceId
             << " | Location: " << location
             << " | Status: " << status
             << " | Last Updated: " << lastUpdated << endl;
    }
};

int main() {
    vector<SmartDevice> devices;

    devices.emplace_back("D001", "Living Room", "OFF", "08:00");
    devices.emplace_back("D002", "Bedroom", "ON", "08:05");
    devices.emplace_back("D003", "Main Door", "LOCKED", "08:10");
    devices.emplace_back("D004", "Kitchen", "OFF", "08:15");

    cout << "=== Smart Home Dashboard ===" << endl;

    for (const auto& device : devices) {
        device.display();
    }

    devices[0].switchOn("09:00");
    devices[1].switchOff("09:05");
    devices[2].changeStatus("UNLOCKED", "09:10");

    cout << "\n=== Updated Home Dashboard ===" << endl;

    for (const auto& device : devices) {
        device.display();
    }

    return 0;
}