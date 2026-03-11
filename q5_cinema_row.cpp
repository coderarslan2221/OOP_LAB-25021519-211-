#include <iostream>
using namespace std;

class CinemaRow {
private:
    bool* seats; // Pointer to dynamic array [cite: 136]
    int numSeats;

public:
    CinemaRow(int n) : numSeats(n) {
        seats = new bool[n]; // Allocate on heap [cite: 138]
        for (int i = 0; i < n; i++) seats[i] = false;
    }

    void bookSeat(int index) {
        if (index < 0 || index >= numSeats) {
            cout << "Error: Seat index " << index << " is out of bounds." << endl;
        } else if (seats[index]) {
            cout << "Error: Seat " << index << " is already booked." << endl;
        } else {
            seats[index] = true;
            cout << "Seat " << index << " booked successfully." << endl;
        }
    }

    // Overloading subscript operator [cite: 140]
    bool operator[](int index) const {
        if (index >= 0 && index < numSeats) return seats[index];
        return false;
    }

    ~CinemaRow() {
        delete[] seats; // Prevent memory leak [cite: 141, 142]
        cout << "Row memory freed." << endl;
    }
};

int main() {
    CinemaRow row(5);
    row.bookSeat(2);
    row.bookSeat(2);
    row.bookSeat(8);
    cout << "Is seat 2 booked? " << (row[2] ? "Yes" : "No") << endl;
    return 0;
}