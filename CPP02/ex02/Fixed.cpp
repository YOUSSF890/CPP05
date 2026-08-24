#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() {
    fixed_point = 0;
}

Fixed::Fixed(const Fixed &a) {
    fixed_point = a.getRawBits();
}

Fixed::Fixed(int const b) {

    fixed_point = b << fractional_bits;
}

Fixed::Fixed(float const c) {
    float value = c * (float)(1 << fractional_bits);
    fixed_point = roundf(value);
}

int Fixed::getRawBits( void ) const {
    return(fixed_point);
}

void Fixed::setRawBits( int const raw ) {
    fixed_point = raw;
}

float Fixed::toFloat( void ) const {
    float value =  fixed_point / (float)(1 << fractional_bits);
    return (value);
}

int Fixed::toInt( void ) const
{
    int value =  fixed_point / (1 << fractional_bits);
    return (value);
}

Fixed& Fixed::operator=(const Fixed& c)
{
    fixed_point = c.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os,const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}


bool Fixed::operator>(const Fixed& fixed) const {
    return (fixed_point > fixed.fixed_point);
}

bool Fixed::operator<(const Fixed& fixed) const {
    return (fixed_point < fixed.fixed_point);
}

bool Fixed::operator>=(const Fixed& fixed) const {
    return (fixed_point >= fixed.fixed_point);
}

bool Fixed::operator<=(const Fixed& fixed) const {
    return (fixed_point <= fixed.fixed_point);
}

bool Fixed::operator!=(const Fixed& fixed) const {
    return (fixed_point != fixed.fixed_point);
}


Fixed Fixed::operator+(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = fixed_point + fixed.fixed_point;
    return (c);
}

Fixed Fixed::operator*(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = ((long)fixed_point * fixed.fixed_point) / (1 << fractional_bits);
    return (c);
}

Fixed Fixed::operator/(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = ((float)fixed_point / (float)fixed.fixed_point) * (1 << fractional_bits);
    return (c);
}

Fixed Fixed::operator-(const Fixed& fixed) const {
    Fixed c;
    c.fixed_point = fixed_point - fixed.fixed_point;
    return (c);
}


Fixed& Fixed::operator++() {

    fixed_point += 1;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed time(*this);
    fixed_point += 1;
    return (time);
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 < fixed2)
        return (fixed1);
    else
        return (fixed2);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 <= fixed2)
        return (fixed1);
    else
        return (fixed2);
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 > fixed2)
        return (fixed1);
    else
        return (fixed2);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed & fixed2)
{
    if (fixed1 >= fixed2)
        return (fixed1);
    else
        return (fixed2);
}

Fixed::~Fixed() {}