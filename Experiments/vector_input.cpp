#include <expected>
#include <iostream>
#include <vector>
#include <limits>

void vectorExperiment() {
    std::vector<int> numbers{0, 1};
    numbers.push_back(2);
    numbers.insert(numbers.begin(), -1);
    auto iterator = numbers.begin() + 2;
    std::advance(iterator, 2);
    numbers.insert(iterator, 41);
    for (const auto& number : numbers) {
        std::cout << number << '\n';
    }
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

int main() {
    // vectorExperiment();
    std::cout << "Please enter some numbers.\n";
    std::vector<double> numbers{};
    auto number {getNumber(std::cin)};
    while(number.has_value())
    {
        numbers.push_back(number.value());
        std::cout << "Got " << number.value() << '\n';
        number = getNumber(std::cin);
    }
    std::cout << number.error() << '\n';

    std::cout << "You entered: \n";
    for (const auto& number : numbers) {
        std::cout << number << '\n';
    }
}