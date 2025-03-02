#include <iostream>
#include <vector>
using namespace std;

int main() {
    /* Type your code here. */
    size_t listSize{};
    cin >> listSize;
    vector<int> userValues(listSize);

    for (size_t i{}; i < listSize; ++i) {
        cin >> userValues.at(i);
    }

    int temp = userValues.back();
    for (size_t i{userValues.size() - 1}; i >= 0; --i) {
        if (i == 0) {
            userValues.at(i) = temp;
            break;
        } else {
            userValues.at(i) = userValues.at(i - 1);
        }
    }
    for (size_t i{0}; i < userValues.size(); ++i) {
        cout << userValues.at(i) << " ";
    }

    return 0;
}
