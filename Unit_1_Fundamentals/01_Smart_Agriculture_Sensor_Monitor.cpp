#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SoilSensor {
private:
    string sensorId;
    double moistureLevel;
    string timestamp;

public:
    SoilSensor(string id, double moisture, string time)
        : sensorId(id), moistureLevel(moisture), timestamp(time) {}

    void readSensor(double newMoisture, string newTime) {
        moistureLevel = newMoisture;
        timestamp = newTime;
    }

    void displayData() const {
        cout << "Sensor: " << sensorId
             << " | Moisture: " << moistureLevel << "%"
             << " | Time: " << timestamp << endl;
    }
};

int main() {
    vector<SoilSensor> farmSensors;

    farmSensors.emplace_back("S001", 45.2, "08:00");
    farmSensors.emplace_back("S002", 52.8, "08:00");
    farmSensors.emplace_back("S003", 38.5, "08:00");

    cout << "=== Morning Sensor Readings ===" << endl;

    for (const auto& sensor : farmSensors) {
        sensor.displayData();
    }

    farmSensors[0].readSensor(47.5, "09:00");

    cout << "\n=== Updated Reading ===" << endl;
    farmSensors[0].displayData();

    return 0;
}