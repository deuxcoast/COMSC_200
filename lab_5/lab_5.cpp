#include "Distance.h"

using namespace std;

int main() {
    int meters{};
    double centimeters{};

    cout << "Enter a distance in meters: ";
    cin >> meters;

    cout << "Enter a distance in centimeters: ";
    cin >> centimeters;

    Distance dist{meters, centimeters};

    cout << dist;

    return 0;
}
