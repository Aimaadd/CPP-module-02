#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed () : store(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    store = fixed.store;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return store;
}

void Fixed::setRawBits(int const raw) {
    store = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

Fixed& Fixed::operator=(Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    store = fixed.store;
    return *this;
}