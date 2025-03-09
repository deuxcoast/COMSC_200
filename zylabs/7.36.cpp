#include <iostream>
#include "GVDie.h"
using namespace std;

int main() {
    int goal{};
    int credits{};
    int rounds;
    int seed{};
    int total{};
    GVDie die1 = GVDie();
    GVDie die2 = GVDie();

    // Read random seed to support testing (do not alter)
    cin >> seed;
    srand(seed);

    // Read starting credits
    cin >> credits;

    /* Type your code here */
    while (credits > 0) {
        die1.Roll();
        die2.Roll();
        total = die1.GetValue() + die2.GetValue();

        if (total == 7 || total == 11) {
            credits++;
        } else if (total == 2 || total == 3 || total == 12) {
            credits--;
        } else {
            goal = total;
        }
        cout << "Dice total: " << total << endl;

        if (goal <= 0) {
            while (true) {
                die1.Roll();
                die2.Roll();

                total = die1.GetValue() + die2.GetValue();

                if (die1.GetValue() == 7 || die2.GetValue() == 7) {
                    credits--;
                    break;
                } else if (total == goal) {
                    credits++;
                    break;
                }
            }
            goal = -1;
            cout << "Dice total: " << total << endl;
        }
        cout << "Credits: " << credits << endl;
        rounds++;
    }

    cout << "Rounds: " << rounds << endl;

    return 0;
}
