#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>
#include <stdexcept>
#include <vector>
#include "input.h"

void trading_game(const std::vector<double> &prices) {
    const double initial_funds{100.0};
    double funds{initial_funds};
    int number_of_shares{0};

    for (auto price: prices) {
        auto status = std::format("Funds ${:.2f}, Shares {} ", funds, number_of_shares);
        std::println("{}", status);
        auto price_message = std::format("Current price: ${:.2f} ", price);
        std::println("{: >{}} ", price_message, status.size());
        std::println("Press (s) to sell, (b) to buy ");
        std::print(" or something else to continue> ");
        char choice{};
        std::cin >> choice;

        if (choice == 's') {
            if (number_of_shares > 0) {
                --number_of_shares;
                funds += price;
            } else {
                std::println("No stock to sell");
            }
        } else if (choice == 'b') {
            if (price <= funds) {
                ++number_of_shares;
                funds -= price;
            } else {
                std::println("Insufficient funds");
            }
        }
    }
    std::println("Total profit ${:.2f} ", funds - initial_funds);
}

void write_to_file_improved(const std::vector<double> &prices, const std::string &filename) {
    const std::filesystem::path path = std::filesystem::current_path();
    const auto fully_pathed_filename = path / filename;
    std::ofstream file{filename};
    if (file) {
        for (auto price: prices) {
            std::println(file, "{:.2f}", price);
        }
        std::println("Wrote to: {}", fully_pathed_filename.string());
    } else {
        throw std::runtime_error(std::format("Failed to write to {}", fully_pathed_filename.string()));
    }
}

int main(int argc, char *argv[]) {
    const auto prices = (argc > 1) ? stock_prices::read_from_file(argv[1]) : stock_prices::get_prices(100.0, 10, 0.05);
    write_to_file_improved(prices, "prices.txt");
    trading_game(prices);
}
