#include <iostream>
using namespace std;

class TransitCard {
private:
    double balance;
    bool isActiveTrip;

public:
    TransitCard(double initialBalance) : balance(initialBalance), isActiveTrip(false) {}

    void tapIn() {
        if (isActiveTrip) {
            cout << "Error: Already on an active trip!" << endl;
        } else if (balance < 2.50) {
            cout << "Error: Insufficient balance to tap in." << endl;
        } else {
            isActiveTrip = true;
            cout << "Tap-in successful." << endl;
        }
    }

    void tapOut() {
        if (!isActiveTrip) {
            cout << "Error: Cannot tap out, no active trip!" << endl;
        } else {
            balance -= 2.50;
            isActiveTrip = false;
            cout << "Tap-out successful. Remaining balance: $" << balance << endl;
        }
    }

    void operator-=(double penalty) {
        balance -= penalty;
    }

    bool operator!() const {
        return balance == 0.0;
    }
};

int main() {
    TransitCard card(5.00);
    card.tapIn();
    card.tapIn();
    card.tapOut();
    card.tapOut();
    if (!card) { cout << "Empty!" << endl; }
    return 0;
}