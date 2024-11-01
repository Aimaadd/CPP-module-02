#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

const int Fixed::frac_bits = 8;

Fixed::Fixed (const int num) {
    value = num << frac_bits;
}

Fixed::Fixed(const float num) {
    value = roundf(num * (1 << frac_bits));
}

Fixed::Fixed(const Fixed& fixed) {
    value = fixed.value;
}

Fixed::~Fixed() {
}

int Fixed::toInt(void) const {
    return value >> frac_bits;
}

float    Fixed::toFloat(void) const {
    return (float)value / (1 << frac_bits);
}

int Fixed::getRawBits(void) const {
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

bool Fixed::operator==(const Fixed& fixed) const{
    if (value == fixed.value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& fixed) const{
    if (value < fixed.value)
        return true;
    return false;
}

bool Fixed::operator>(const Fixed& fixed) const{
    if (value > fixed.value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& fixed) const{
    if (value <= fixed.value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& fixed) const{
    if (value >= fixed.value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& fixed) const{
    if (value != fixed.value)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed& fixed) const {
    Fixed result;
    result.setRawBits(value + fixed.value);
    return result;
}

Fixed Fixed::operator-(const Fixed& fixed) const {
    Fixed result;
    result.setRawBits(value - fixed.value);
    return result;
}

Fixed Fixed::operator*(const Fixed& fixed) const {
    Fixed result;
    result.setRawBits((value * fixed.value) >> frac_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed& fixed) const {
    Fixed result;
    result.setRawBits((value << frac_bits) / fixed.value);
    return result;
}

Fixed Fixed::operator++(int) {
    Fixed result(*this);
    value++;
    return result;
}

Fixed& Fixed::operator++() {
    value++;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed result(*this);
    value--;
    return result;
}

Fixed& Fixed::operator--() {
    value--;
    return *this;
}

Fixed Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}

Fixed Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
    if (fixed1 > fixed2)
        return fixed1;
    return fixed2;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}