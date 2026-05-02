#include <cassert>
#include <iostream>
#include <sstream>
#include <sstream>
#include <exception>

double getNumber(std::istream& inputStream) {
    double number{};
    inputStream >> number;
    if (inputStream) {
        return number;
    }
    throw std::exception{};
}

int main() {
    try {
        std::cout << "Please enter a number: \n";
        double number{getNumber(std::cin)};
        std::cout << number << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error" << std::endl;
    }
}