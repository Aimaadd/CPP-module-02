#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

const int Fixed::frac_bits = 8;

Fixed::Fixed (const int num) {
    std::cout << "Int constructor called" << std::endl;
    value = num << frac_bits;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    value = roundf(num * (1 << frac_bits));
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    value = fixed.value;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const {
    return value >> frac_bits;
}

float    Fixed::toFloat(void) const {
    return (float)value / (1 << frac_bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}