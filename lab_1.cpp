#include <iomanip>
#include <iostream>

constexpr int ARR_SIZE = 10;

struct Circle {
    double m_radius{};
    double m_circumference{};
    double m_area{};

    Circle() = default;
    Circle(double radius) : m_radius{radius} {
        m_circumference = 2 * M_PI * radius;
        m_area = M_PI * radius * radius;
    }
};

void GetUserInput(Circle circle_arr[]) {
    double user_input{};

    for (size_t i{}; i < ARR_SIZE; i++) {
        std::cout << "Enter radius of circle " << i + 1 << ": ";
        std::cin >> user_input;

        // TODO: validate user input
        circle_arr[i] = user_input;
    }
}

Circle FindLargestCircle(Circle circle_arr[]) {
    int maxIdx{0};

    for (size_t i{1}; i < ARR_SIZE; i++) {
        if (circle_arr[i].m_area > circle_arr[maxIdx].m_area) {
            maxIdx = static_cast<int>(i);
        }
    }

    return circle_arr[maxIdx];
}

int main() {
    Circle user_circles[ARR_SIZE];

    GetUserInput(user_circles);
    Circle largest_circle = {FindLargestCircle(user_circles)};
    std::cout << std::setprecision(2);
    std::cout << "Area of the largest circle: " << largest_circle.m_area
              << std::endl;
}
