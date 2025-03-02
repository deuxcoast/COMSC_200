#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> userValues(10);

    for (size_t i{}; i < 10; ++i) {
        cin >> userValues.at(i);
    }

    int minVal{userValues.at(0)}, maxVal{userValues.at(0)};
    int sumVals{userValues.at(0)};

    for (size_t i{1}; i < 10; ++i) {
        sumVals += userValues.at(i);
        if (userValues.at(i) > maxVal)
            maxVal = userValues.at(i);
        if (userValues.at(i) < minVal)
            minVal = userValues.at(i);
    }

    double avg{sumVals / 10.0};

    cout << minVal << " " << maxVal << " " << avg << endl;

    return 0;
}
