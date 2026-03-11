#include <iostream>
using namespace std;

class Elevator {
private:
    int currentFloor;
    double currentWeight;
    const double maxWeight = 500.0; // Fixed at 500.0 kg 

public:
    Elevator(int floor = 1, double weight = 0.0) : currentFloor(floor), currentWeight(weight) {}

    Elevator& loadPassenger(double weight) {
        if (currentWeight + weight > maxWeight) {
            cout << "Error: Weight exceeds 500.0kg. Passenger rejected." << endl;
        } else {
            currentWeight += weight;
        }
        return *this; // Enables method chaining
    }

    Elevator& goToFloor(int floor) {
        if (floor < 1 || floor > 10) {
            cout << "Error: Floor " << floor << " is out of bounds." << endl;
        } else {
            currentFloor = floor;
        }
        return *this;
    }

    bool operator==(const Elevator& other) const {
        return this->currentFloor == other.currentFloor;
    }

    ~Elevator() {
        cout << "Elevator powering down at floor " << currentFloor << "." << endl;
    }
};

int main() {
    Elevator el(1, 0);
    el.loadPassenger(400.0).loadPassenger(150.0).goToFloor(5).goToFloor(12);
    return 0;
}