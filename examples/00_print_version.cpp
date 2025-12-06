#include <iostream>

#include <matho/config.hpp>

int main(int argc, char const * argv[]) {
    std::cout << "Fraction version: ";
    std::cout << FRACTION_VERSION_MAJOR << ".";
    std::cout << FRACTION_VERSION_MINOR << ".";
    std::cout << FRACTION_VERSION_PATCH << ".";
    std::cout << FRACTION_VERSION_TWEAK;
    std::cout << std::endl;

    return 0;
}
