#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed () : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    value = fixed.value;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

Fixed& Fixed::operator=(Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    value = fixed.value;
    return *this;
}