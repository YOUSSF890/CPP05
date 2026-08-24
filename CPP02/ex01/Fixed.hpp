#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits;
    public:
        Fixed();
        Fixed(int const b);
        Fixed(float const b);
        ~Fixed();
        Fixed& operator=(const Fixed& c);
        Fixed(const Fixed &a);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif