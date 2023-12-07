#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int value;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const int value, const int bits);
        Fixed(Fixed const &obj);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        // std::ostream& Fixed::operator <<(std::ostream& tmp, Fixed const &obj);

};

#endif