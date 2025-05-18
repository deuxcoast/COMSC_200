#include <iostream>
#include <vector>

void get_input(std::vector<int>& list, int& target) {
    std::cout << "Enter 10 integers:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        list.push_back(num);
    }

    std::cout << "Enter value to find: ";
    std::cin >> target;
}

size_t linear_search(const std::vector<int>& list, int target) {
    for (size_t i{}; i < list.size(); ++i) {
        if (list.at(i) == target) {
            return i;
        }
    }
    return static_cast<size_t>(-1);
}

size_t binary_search(const std::vector<int>& list, int target) {
    size_t left = 0;
    size_t right = list.size() - 1;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;

        if (list[mid] == target) {
            return mid;
        } else if (list[mid] < target) {
            left = mid + 1;
        } else {
            if (mid == 0)
                break;  // To prevent size_t underflow
            right = mid - 1;
        }
    }
    return static_cast<size_t>(-1);
}

void bubble_sort(std::vector<int>& list) {
    for (size_t i = 0; i < list.size(); ++i) {
        for (size_t j = 0; j < list.size() - i - 1; ++j) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
}

void selection_sort(std::vector<int>& list) {
    for (size_t i = 0; i < list.size(); ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < list.size(); ++j) {
            if (list[j] < list[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(list[i], list[min_idx]);
    }
}

void print_list(const std::vector<int>& list) {
    for (auto num : list) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> list;
    int target{};

    get_input(list, target);

    size_t linear_result = linear_search(list, target);
    std::cout << "Linear Search: target value (" << target << ") ";
    if (linear_result != static_cast<size_t>(-1)) {
        std::cout << "found at index " << linear_result << "." << std::endl;
    } else {
        std::cout << "not found." << std::endl;
    }

    // Bubble sort
    std::vector<int> bubble_list = list;
    bubble_sort(bubble_list);
    std::cout << "Bubble Sorted List: ";
    print_list(bubble_list);

    size_t bubble_binary_result = binary_search(bubble_list, target);
    std::cout << "Binary Search after Bubble Sort: ";
    if (bubble_binary_result != static_cast<size_t>(-1)) {
        std::cout << "found at index " << bubble_binary_result << "."
                  << std::endl;
    } else {
        std::cout << "number not found." << std::endl;
    }

    // Selection sort
    std::vector<int> selection_list = list;
    selection_sort(selection_list);
    std::cout << "Selection Sorted List: ";
    print_list(selection_list);

    size_t selection_binary_result = binary_search(selection_list, target);
    std::cout << "Binary Search after Selection Sort: ";
    if (selection_binary_result != static_cast<size_t>(-1)) {
        std::cout << "found at index " << selection_binary_result << "."
                  << std::endl;
    } else {
        std::cout << "number not found." << std::endl;
    }

    return 0;
}
