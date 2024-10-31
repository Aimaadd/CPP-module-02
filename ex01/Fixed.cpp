#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    store = 0;
}

const int Fixed::frac_bits = 8;

Fixed::Fixed (const int num) {
    std::cout << "Int constructor called" << std::endl;
    store = num << frac_bits;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    store = roundf(num * (1 << frac_bits));
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    store = fixed.store;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const {
    return store >> frac_bits;
}

float    Fixed::toFloat(void) const {
    return (float)store / (1 << frac_bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}