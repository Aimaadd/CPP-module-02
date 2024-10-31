#include <cmath>
#include <iostream>

class Fixed {
    private :
        int store;
        static const int frac_bits;
    public :
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& fixed);
        ~Fixed();
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);