#include <array>
#include <expected>
#include <iostream>
#include <ostream>

void arrayExperiment() {
    std::array<double, 5> numbers{};
    std::cout << numbers[0] << std::endl;
    numbers[0] = 42;
    std::cout << numbers[0] << std::endl;
}

std::expected<double, std::string> getNumber(std::istream& input) {
    double number{};
    input >> number;
    if (input) {
        return number;
    }
    input.clear();
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return std::unexpected {"That's not a number"};
}

void showNumber(const std::array<double, 5u>& numbers) {
    for (const auto& number : numbers) {
        std::cout << number << '\n';
    }
}

void maxNumber(const std::array<double, 5u>& numbers) {
    double biggest {numbers[0]};
    for (const auto& number : numbers) {
        if (number > biggest) {
            biggest = number;
        }
    }
    std::cout << biggest << '\n';
}

int main() {
    std::cout << "Please enter a number: \n";
    std::array<double, 5u> numbers{};
    size_t count {0u};
    while (count < numbers.size()) {
        std::cout << '>';
        auto number = getNumber(std::cin);
        if (number.has_value()) {
            numbers[count] = number.value();
            std::cout << number.value() << '\n';
        } else {
            std::cout << number.error() << '\n';
        }
        ++count;
    }
}