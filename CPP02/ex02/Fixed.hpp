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
        Fixed(const Fixed &a);

        Fixed& operator=(const Fixed& c);
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        
        float   toFloat( void ) const;
        int     toInt( void ) const;

        static Fixed& min(Fixed& fixed1, Fixed & fixed2);
        static const Fixed& min(const Fixed& fixed1, const Fixed & fixed2);
        static Fixed& max(Fixed& fixed1, Fixed & fixed2);
        static const Fixed& max(const Fixed& fixed1, const Fixed & fixed2);
        

        bool operator>(const Fixed& fixed) const;
        bool operator<(const Fixed& fixed) const;
        bool operator>=(const Fixed& fixed) const;
        bool operator<=(const Fixed& fixed) const;
        bool operator!=(const Fixed& fixed) const;
        
        Fixed operator+(const Fixed& fixed) const;
        Fixed operator*(const Fixed& fixed) const;
        Fixed operator/(const Fixed& fixed) const;
        Fixed operator-(const Fixed& fixed) const;
        
        Fixed& operator++();
        Fixed operator++(int);

        ~Fixed();

};

std::ostream& operator<<(std::ostream& os,const Fixed& fixed);

#endif