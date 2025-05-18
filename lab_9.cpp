#include <exception>
#include <iostream>
using namespace std;

int main() {
    int donuts, milk;
    double dpg;
    cout << "Enter number of donuts:\n";
    cin >> donuts;
    cout << "Enter number of glasses of milk:\n";
    cin >> milk;
    try {
        if (milk <= 0)
            throw -1;
        else {
            dpg = donuts / static_cast<double>(milk);

            cout << donuts << " donuts.\n"
                 << milk << " glasses of milk.\n"
                 << "You have " << dpg << " donuts for each glass of milk.\n";
        }

    } catch (int) {
        cout << donuts << " donuts, and No Milk!\n"
             << "Go buy some milk.\n";
    }
    cout << "End of program.\n";
    return 0;
}
