#include <algorithm>  // for sort()
#include <cstddef>
#include <iomanip>  // for setprecision()
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t count;
    int num;

    // Step 0: Input values
    cin >> count;
    vector<int> nums;
    for (size_t i = 0; i < count; ++i) {
        cin >> num;
        nums.push_back(num);
    }

    // Step 1: Find minimum and maximum values
    /* Type your code here. */
    int min{nums[0]};
    int max{nums[0]};
    int sum{nums[0]};

    for (size_t j{1}; j < nums.size(); ++j) {
        sum += nums.at(j);
        if (nums[j] < min)
            min = nums.at(j);
        if (nums[j] > max)
            max = nums.at(j);
    }
    double mean = sum / static_cast<double>(nums.size());
    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
    cout << "Mean: " << fixed << setprecision(1) << mean << endl;

    // Step 3: Check if palindrome
    /* Type your code here. */
    bool palindrome{true};
    for (size_t j{1}; j < nums.size() / 2; ++j) {
        if (nums.at(j) != nums.at(nums.size() - 1 - j)) {
            palindrome = false;
        }
    }

    cout << "Palindrome: " << boolalpha << palindrome << endl;

    // Sort vector elements in ascending order
    sort(nums.begin(), nums.end());

    // Step 4: Find and output median
    /* Type your code here. */
    double median{};
    if (nums.size() % 2 == 0) {
        median =
            (nums.at(nums.size() / 2 - 1) + nums.at(nums.size() / 2)) / 2.0;
    } else {
        size_t middle{};
        middle = nums.size() / 2;
        median = nums.at(middle);
    }
    cout << "Median: " << median << endl;

    vector<int> freq_vec(static_cast<size_t>(max) + 1);
    // Step 5: Find and output mode
    /* Type your code here. */
    for (size_t i{}; i < nums.size(); ++i) {
        int num{nums.at(i)};
        freq_vec.at(static_cast<size_t>(num)) += 1;
    }

    int max_freq{};
    int mode{};
    for (size_t i{}; i < freq_vec.size(); ++i) {
        if (freq_vec.at(i) > max_freq) {
            max_freq = freq_vec.at(i);
            mode = static_cast<int>(i);
        }
    }
    cout << "Mode: " << mode << endl;

    return 0;
}
