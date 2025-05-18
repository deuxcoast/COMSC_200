#include <iomanip>
#include <iostream>
#include <stdexcept>
int main() {
    int monthly_pay{};
    int hours_worked{};
    int days_worked{};
    double rate_day{};
    double rate_hr{};

    while (true) {
        try {
            std::cout << "Enter your monthly pay: ";
            std::cin >> monthly_pay;

            if (monthly_pay < 0) {
                std::cout << "Exiting";
                break;
            }

            std::cout << "Enter hours worked in last month: ";
            std::cin >> hours_worked;
            if (hours_worked > 720 || hours_worked < 0) {
                throw std::runtime_error(
                    "Error: Hours worked must be between 0 and 720");
            }

            std::cout << "Enter days worked in last month: ";
            std::cin >> days_worked;

            if (days_worked > 31 || days_worked < 0) {
                throw std::invalid_argument(
                    "Error: Days worked must be between 0 and 31");
            }

            if (days_worked != 0 && hours_worked == 0) {
                throw std::invalid_argument("Error: Division by zero");
            }
            if (days_worked == 0 && hours_worked != 0) {
                throw std::invalid_argument("Error: Division by zero");
            }

            rate_day = static_cast<double>(monthly_pay) / days_worked;
            rate_hr = static_cast<double>(monthly_pay) / hours_worked;

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Daily Rate: $" << rate_day << std::endl;
            std::cout << "Hourly Rate: $" << rate_hr << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            std::cout << "Try again\n" << std::endl;
        }
    }
}
