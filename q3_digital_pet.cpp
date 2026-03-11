#include <iostream>
#include <string>

using namespace std;

class DigitalPet {
private:
    int hunger; // Range 0-100
    int energy; // Range 0-100 

public:
    // Parameterized constructor
    DigitalPet(int h, int e) : hunger(h), energy(e) {}

    // Method Chaining: feed() decreases hunger by 20 
    DigitalPet& feed() {
        hunger -= 20;
        if (hunger < 0) {
            hunger = 0;
            cout << "Hunger is bounded at 0." << endl;
        }
        return *this;
    }

    // Method Chaining: sleep() increases energy by 30 
    DigitalPet& sleep() {
        energy += 30;
        if (energy > 100) {
            energy = 100;
            cout << "Energy is bounded at 100." << endl;
        }
        return *this;
    }

    // Prefix ++: Increases hunger and decreases energy 
    DigitalPet& operator++() {
        hunger = (hunger + 10 > 100) ? 100 : hunger + 10;
        energy = (energy - 10 < 0) ? 0 : energy - 10;
        return *this;
    }

    // Postfix ++: Returns ORIGINAL state before changes 
    DigitalPet operator++(int) {
        DigitalPet originalState = *this; // Save current state
        ++(*this); // Use prefix logic to update current object
        return originalState; // Return the old state
    }

    void printStats() {
        cout << "Current Stats -> Hunger: " << hunger << " , Energy: " << energy << endl;
    }
};

int main() {
    // Example usage from lab document
    DigitalPet pet(10, 90); 
    
    // Test method chaining
    pet.feed().sleep();
    
    // Display results 
    pet.printStats();

    return 0;
}