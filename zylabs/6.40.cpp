#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    /* Type your code here. */
    size_t listSize{};
    cin >> listSize;
    vector<int> nums(listSize);

    for (size_t i{}; i < listSize; ++i) {
        cin >> nums.at(i);
    }

    for (size_t i{}, j{nums.size() - 1}; i <= j; ++i, --j) {
        if (nums.size() == 1)
            break;
        if (nums.at(i) != nums.at(j)) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;

    return 0;
}
