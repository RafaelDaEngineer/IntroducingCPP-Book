#include <cassert>
#include <iostream>
#include <sstream>
#include <sstream>
#include <exception>
#include <stdexcept>

double getNumber(std::istream& inputStream) {
    double number{};
    inputStream >> number;
    if (inputStream) {
        if (number > 0.0) {
            return number;
        }
        throw std::invalid_argument{"Negative numbers are not allowed"};
    }
    throw std::exception{};
}

int main() {
    try {
        std::cout << "Please enter a number: \n";
        double number{getNumber(std::cin)};
        std::cout << number << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error" << std::endl;
    }
}