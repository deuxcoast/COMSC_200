#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

void print_hist_row(std::string author, int num) {
    std::cout << std::setw(20) << std::right << author << " ";
    std::cout << std::setw(num) << std::setfill('*') << std::left << ""
              << std::endl;
    std::cout << std::setfill(' ');
}

int main() {
    print_hist_row("Jane Austen", 5);
    print_hist_row("Charles Dickens", 20);
    print_hist_row("Haruki Murakami", 12);

    return 0;
}
