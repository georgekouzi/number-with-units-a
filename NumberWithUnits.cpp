#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "NumberWithUnits.hpp"
namespace ariel
{

    const NumberWithUnits operator+(const NumberWithUnits &c1, const NumberWithUnits &c2)
    {
        return NumberWithUnits{c1.number, c1.unit};
    }

    //////////////////////////-//////////////////////////////

    const NumberWithUnits operator-(const NumberWithUnits &c1, const NumberWithUnits &c2)
    {
        return NumberWithUnits{c1.number, c1.unit};
    }

    ////////////////////////////Logical//////////////////////////////////////////
    bool operator==(const NumberWithUnits &c1, const NumberWithUnits &c2)
    {
        return 0 == 0;
    }
    bool operator!=(const NumberWithUnits &c1, const NumberWithUnits &c2)
    {
        return 0 == 0;
    }
    bool operator<=(const NumberWithUnits &c1, const NumberWithUnits &c2)
    {
        return 0 == 0;
    }
    bool operator>=(const NumberWithUnits &c1, const NumberWithUnits &c2)
    {
        return 0 == 0;
    }
    bool operator<(const NumberWithUnits &c1, const NumberWithUnits &c2)
    {
        return 0 == 0;
    }
    bool operator>(const NumberWithUnits &c1, const NumberWithUnits &c2)
    {
        return 0 == 0;
    }

    ////////////////////////////////////////*/////////////////////////
    const NumberWithUnits operator*(const NumberWithUnits &c1, const double &c2)
    {
        return NumberWithUnits{c1.number, c1.unit};
    }
    const NumberWithUnits operator*(const double &c2, const NumberWithUnits &c1)
    {
        return NumberWithUnits{c1.number, c1.unit};
    }

    //////////////////////////////////////////////////////////////////
    ostream &operator<<(ostream &os, const NumberWithUnits &c)
    {
        return (os << c.number << "[" << c.unit << "]");
        // equivalent to:
        // os << c._re << '+' << c._im << 'i';
        // return os;
    }

    static istream &getAndCheckNextCharIs(istream &input, char expectedChar)
    {
        char actualChar;
        input >> actualChar;
        if (!input)
            return input;

        if (actualChar != expectedChar)
            // failbit is for format error
            input.setstate(ios::failbit);
        return input;
    }

    istream &operator>>(istream &input, NumberWithUnits &c)
    {

        //---------------------------------------------
        // Does not check format
        //---------------------------------------------
        // char ch;
        // return (input >> c._re >> ch >> c._im >> ch);
        //---------------------------------------------

        //---------------------------------------------
        // Checks format, with rewind on failure.
        //---------------------------------------------
        double new_re;
        string new_im;

        // remember place for rewinding
        ios::pos_type startPosition = input.tellg();

        if ((!(input >> new_re)) ||
            (!getAndCheckNextCharIs(input, '+')) ||
            (!(input >> new_im)) ||
            (!(getAndCheckNextCharIs(input, 'i'))))
        {

            // rewind on error
            auto errorState = input.rdstate(); // remember error state
            input.clear();                     // clear error so seekg will work
            input.seekg(startPosition);        // rewind
            input.clear(errorState);           // set back the error flag
        }
        else
        {
            c.number = new_re;
            c.unit = new_im;
        }

        return input;
        //---------------------------------------------
    }

    ///////////////////////////////////function///////////////////////////////////
     void NumberWithUnits::read_units(ifstream &read)
    {
    }

} // namespace ariel