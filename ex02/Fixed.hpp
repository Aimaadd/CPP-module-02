#include <cmath>
#include <iostream>

class Fixed {
    private :
        int value;
        static const int frac_bits;
    public :
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& fixed);
        ~Fixed();
        float toFloat(void) const;
        int toInt(void) const;
        void setRawBits(int const raw);
        int getRawBits(void) const;
        bool operator==(const Fixed& fixed) const;
        bool operator<(const Fixed& fixed) const;
        bool operator>(const Fixed& fixed) const;
        bool operator<=(const Fixed& fixed) const;
        bool operator>=(const Fixed& fixed) const;
        bool operator!=(const Fixed& fixed) const;
        Fixed operator+(const Fixed& fixed) const;
        Fixed operator-(const Fixed& fixed) const;
        Fixed operator*(const Fixed& fixed) const;
        Fixed operator/(const Fixed& fixed) const;
        Fixed operator++(int);
        Fixed& operator++();
        Fixed operator--(int);
        Fixed& operator--();
        Fixed min(const Fixed& fixed1, const Fixed& fixed2);
        static Fixed max(const Fixed& fixed1, const Fixed& fixed2);
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};
