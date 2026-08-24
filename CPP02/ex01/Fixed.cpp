#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const Fixed &a)
{
    std::cout << "Copy constructor called" << std:: endl;
    *this = a;
}

Fixed::Fixed(int const b)
{
    fixed_point = b << fractional_bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const c)
{
    float value = c * (float)(1 << fractional_bits);
    fixed_point = roundf(value);
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return(fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}


float Fixed::toFloat( void ) const
{
    float value = fixed_point / (float)(1 << fractional_bits);
    return (value);
}

int Fixed::toInt( void ) const
{
    int value =  fixed_point / (1 << fractional_bits);
    return (value);
}

Fixed& Fixed::operator=(const Fixed& c)
{
    std::cout << "Copy assignment operator called" << std::endl;
    fixed_point = c.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}