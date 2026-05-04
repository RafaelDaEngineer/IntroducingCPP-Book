#include <iostream>
#include <cassert>
#include <sstream>

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

[[nodiscard]] bool getNumber(std::istream& inputStream, double number) {
    inputStream >> number;
    if (inputStream) {
        return true;
    } else {
        inputStream.clear();
        inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}

void someExperiment() {
    double number {};
    bool OK = getNumber(std::cin, number);
    std::cout << OK << std::endl;
}

void testCode() {
    double value{};
    std::stringstream someInput{"1"};
    const bool ok = getNumber(someInput, value);
    assert(ok);
    assert(value == 1);

    double unused{};
    std::stringstream badInput{"a"};
    const bool notOk = getNumber(badInput, unused);
    assert(!notOk);
}


// Compiling a program usually follows this template:
// tool_name [optional flags] source_name.cpp -o output_name
int main() {
    testCode();

    double number{};
    std::cout << "Please enter a number: \n";
    const bool ok = getNumber(std::cin, number);
    if (ok) {
        std::cout << "You entered: " << number << std::endl;
    } else {
        std::cout << "Error" << std::endl;
        std::cout << "Please try again" << std::endl;
        const bool okNow = getNumber(std::cin, number);
        if (okNow) {
            std::cout << "You entered: " << number << std::endl;
        } else {
            std::cout << "Error again" << std::endl;
        }
    }


    return 0;
}
