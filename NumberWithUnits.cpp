#include <iostream>
#include <cassert>
#include <stdio.h>
#include <stdbool.h>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;
namespace ariel
{

    static map<string, map<string, double>> units;
    NumberWithUnits::NumberWithUnits(double a, const string &unit) {}

    void NumberWithUnits::read_units(ifstream &f)
    {
    }
    // adds a conversion between the two newly added strings and all the previous strings
    // which share a common string with a or b.

    void UnitSync(const string a, const string b)
    {
    }
    // Converts a value from a given base string to its value in string dst
    double baseConver(double value, const string base, const string dst)
    {
        return 0;
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &a) const { NumberWithUnits p{9, "km"};
        return p; }
    NumberWithUnits NumberWithUnits::operator+() const { NumberWithUnits p{9, "km"};
        return p; }

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &a) const { NumberWithUnits p{9, "km"};
        return p; }
    NumberWithUnits NumberWithUnits::operator-() const { NumberWithUnits p{9, "km"};
        return p; }
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &a) { return *this; }
    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &a) { return *this; }

    NumberWithUnits &NumberWithUnits::operator++() { return *this; }
    NumberWithUnits NumberWithUnits::operator++(int a) { return *this; }
    NumberWithUnits &NumberWithUnits::operator--() { return *this; }
    NumberWithUnits NumberWithUnits::operator--(int a) { return *this; }
    NumberWithUnits NumberWithUnits::operator*(double num2) const { NumberWithUnits p{9, "km"};
        return p; }
    NumberWithUnits operator*(double a, const NumberWithUnits &b)
    {
        NumberWithUnits z{9, "km"};
        return z;
    }

    ostream &operator<<(ostream &stream, const NumberWithUnits &a) { return stream; }
    istream &operator>>(istream &stream, const NumberWithUnits &a) { return stream; }

    bool NumberWithUnits::operator>(const NumberWithUnits &a) const { return true; }
    bool NumberWithUnits::operator>=(const NumberWithUnits &a) const { return true; }
    bool NumberWithUnits::operator<(const NumberWithUnits &a) const { return true; }
    bool NumberWithUnits::operator<=(const NumberWithUnits &a) const { return true; }
    bool NumberWithUnits::operator==(const NumberWithUnits &a) const { return true; }
    bool NumberWithUnits::operator!=(const NumberWithUnits &a) const { return true; }

}