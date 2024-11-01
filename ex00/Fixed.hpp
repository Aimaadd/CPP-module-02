#include <iostream>

class Fixed {
    private :
        int value;
        static const int frac_bits;
    public :
        Fixed();
        Fixed(Fixed& fixed);
        ~Fixed();
        Fixed& operator=(Fixed& fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw); 
};
