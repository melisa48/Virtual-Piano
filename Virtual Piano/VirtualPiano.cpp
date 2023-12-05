#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

class Piano {
public:
    int bigKey, midKey, back, border;

    Piano() : bigKey(15), midKey(1), back(7), border(15) {}
};

Piano color;

float frequencies[] = { 130.81, 146.83, 164.81, 174.61, 196, 220, 246.94 };

void drawPiano();
void playSound(int key, int multiplier);

int main() {
    int key, multiplier = 4;
    char ch;

    while (true) {
        cout << "Enter a key (a-g) or 'q' to quit: ";
        cin >> ch;

        if (ch == 'q')
            break;

        if (ch >= 'a' && ch <= 'g') {
            key = ch - 'a';
            playSound(key, multiplier);
        }
        else {
            cout << "Invalid input. Please enter a valid key.\n";
        }
    }

    return 0;
}

void drawPiano() {
    // Your drawing logic goes here
    // This function is simplified and should be replaced with a graphics library for a more advanced GUI
}

void playSound(int key, int multiplier) {
    if (key >= 0 && key < 7) {
        float frequency = frequencies[key] * multiplier;
        cout << "Playing sound for key '" << char('A' + key) << "' with frequency: " << frequency << " Hz\n";
        // Add sound-playing logic here (e.g., using a sound library or system commands)
        // For simplicity, we'll use a delay to simulate sound playback
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    else {
        cout << "Invalid key.\n";
    }
}
