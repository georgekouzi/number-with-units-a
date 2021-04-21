#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel
{
    class NumberWithUnits
    {
    private:
        double  number;
        string unit;

    public:
        NumberWithUnits(double  n=0.0, string u=" ") : number(n), unit(u){};
        static void read_units(ifstream &read);
        //////////////////////////+//////////////////////////////////
        NumberWithUnits &operator+=(const NumberWithUnits &other)
        {

            return *this;
        }
        const NumberWithUnits operator+() const
        {
            return *this;
        }

        friend const NumberWithUnits operator+(const NumberWithUnits &c1, const NumberWithUnits &c2);

        //////////////////////////-//////////////////////////////
        NumberWithUnits &operator-=(const NumberWithUnits &other)
        {

            return *this;
        }
        const NumberWithUnits operator-() const
        {
            return *this;
        }
        friend const NumberWithUnits operator-(const NumberWithUnits &c1, const NumberWithUnits &c2);

        ////////////////////////////Logical//////////////////////////////////////////
        friend bool operator==(const NumberWithUnits &c1, const NumberWithUnits &c2);
        friend bool operator!=(const NumberWithUnits &c1, const NumberWithUnits &c2);
        friend bool operator<=(const NumberWithUnits &c1, const NumberWithUnits &c2);
        friend bool operator>=(const NumberWithUnits &c1, const NumberWithUnits &c2);
        friend bool operator<(const NumberWithUnits &c1, const NumberWithUnits &c2);
        friend bool operator>(const NumberWithUnits &c1, const NumberWithUnits &c2);

        ///////////////////++ or --///////////////////////////////////
        NumberWithUnits &operator++()
        {
            return *this;
        }

        // postfix increment:
        const NumberWithUnits operator++(int dummy_flag_for_postfix_increment)
        {
            NumberWithUnits copy = *this;
            return copy;
        }
        NumberWithUnits &operator--()
        {
            return *this;
        }

        // postfix increment:
        const NumberWithUnits operator--(int dummy_flag_for_postfix_increment)
        {
            NumberWithUnits copy = *this;
            return copy;
        }

        ////////////////////////////////////////*/////////////////////////
        friend const NumberWithUnits operator*(const NumberWithUnits &c1, const double &c2);
        friend const NumberWithUnits operator*(const double &c2, const NumberWithUnits &c1);

        //////////////////////////////////////////
        friend ostream &operator<<(ostream &os, const NumberWithUnits &c);
        friend istream &operator>>(istream &is, NumberWithUnits &c);
    };

} // namespace ariel