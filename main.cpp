#include <iostream>

void variablesExample() {
    int number{};
    number = 42;

    // Immutable
    const int constNumber = 42;
}

void limitExample() {
    int largestInt = std::numeric_limits<int>::max();
    double largestDouble = std::numeric_limits<double>::max();
}

void inputOutputExample() {
    std::cout << "Enter a number: \n";
    double number{};
    std::cin >> number;
    std::cout << number << std::endl;
}

void inputExperiment() {
    const double largest = std::numeric_limits<double>::max();
    std::cout << "Please enter a number up to" << largest << std::endl;
    double number{};
    std::cin >> number;
    if (std::cin) {
        std::cout << number << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }
}

// Compiling a program usually follows this template:
// tool_name [optional flags] source_name.cpp -o output_name
int main() {

    return 0;
}
