#include <expected>
#include <iostream>
#include <string>

std::expected<double, std::string> getNumber(std::istream& input) {
    double number{};
    input >> number;
    if (input) {
        return number;
    }
    return std::unexpected {"That's not a number"};
}

int main() {
    std::cout << "Please enter a number: \n";
    while (true) {
        auto number = getNumber(std::cin);
        if (number) {
            std::cout << number.value() << '\n';
        } else {
            std::cout << number.error() << '\n';
            break;
        }
    }
}