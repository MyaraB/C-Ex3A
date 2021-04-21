#include <iostream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "doctest.h"
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;

static vector<string> units = {"m"};
ifstream units_file{"units.txt"};

TEST_CASE("test ++ and -- operators"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{1, "cm"};
    NumberWithUnits b{1, "mm"};
    NumberWithUnits c{1, "km"};
    NumberWithUnits d{1, "m"};
    NumberWithUnits e{2, "apple"};
    CHECK(a++ == NumberWithUnits{1, "cm"});
    CHECK(a == NumberWithUnits{2, "cm"});
    CHECK(++a == NumberWithUnits{3, "cm"});
    CHECK(e == NumberWithUnits{2, "apple"});
    CHECK(e-- == NumberWithUnits{2, "apple"});
    CHECK(e == NumberWithUnits{1, "apple"});
    CHECK(--e == NumberWithUnits{0, "apple"});
    CHECK(e == NumberWithUnits{0, "apple"});
}

TEST_CASE("addition tests"){
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{1, "cm"};
    NumberWithUnits b{1, "mm"};
    NumberWithUnits c{1, "km"};
    NumberWithUnits d{1, "m"};
    NumberWithUnits e{1, "apple"};
    CHECK_THROWS(a+e);
    CHECK_THROWS(b+e); 
    CHECK_EQ(a+b , NumberWithUnits{1.1, "cm"});
    CHECK_EQ(c+d, NumberWithUnits{1.001, "km"});
}

TEST_CASE("test +=, -= operators"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{1, "cm"};
    NumberWithUnits b{1, "mm"};
    NumberWithUnits c{1, "km"};
    NumberWithUnits d{1, "m"};
    NumberWithUnits e{2, "apple"};
    CHECK((a+=b) == NumberWithUnits{1.1, "cm"});
    CHECK(a == NumberWithUnits{1.1, "cm"});
    CHECK((a+=d) == NumberWithUnits{101.1, "cm"});
    CHECK(d == NumberWithUnits{1, "m"});
    CHECK_THROWS(a+=e);
    CHECK_THROWS(b-=e); 
}



TEST_CASE("test : {>, >=, <, <=, ==, !=} operators"){
    NumberWithUnits::read_units(units_file);

    CHECK_LT(NumberWithUnits{1, "km"}  , NumberWithUnits{2, "km"});
    CHECK_LE(NumberWithUnits{1, "km"}  , NumberWithUnits{1, "km"});
    CHECK_GT(NumberWithUnits{3, "km"}, NumberWithUnits{2, "km"});
    CHECK_GE(NumberWithUnits{3, "km"}, NumberWithUnits{3, "km"});
    CHECK_EQ(NumberWithUnits{2, "km"}, NumberWithUnits{2, "km"});
    CHECK_NE(NumberWithUnits{3, "km"}  , NumberWithUnits{5, "km"});

    CHECK_LT(NumberWithUnits{1, "km"}  , NumberWithUnits{2000, "m"});
    CHECK_LE(NumberWithUnits{1, "km"}  , NumberWithUnits{1000, "m"});
    CHECK_GT(NumberWithUnits{3, "km"}, NumberWithUnits{2000, "m"});
    CHECK_GE(NumberWithUnits{3, "km"}, NumberWithUnits{3000, "m"});
    CHECK_EQ(NumberWithUnits{2, "km"}, NumberWithUnits{2000, "m"});
    CHECK_NE(NumberWithUnits{3, "km"}  , NumberWithUnits{5000, "m"});
    
    CHECK_LT(NumberWithUnits{1, "m"}  , NumberWithUnits{101, "cm"});
    CHECK_LE(NumberWithUnits{1, "m"}  , NumberWithUnits{100, "cm"});
    CHECK_GT(NumberWithUnits{3, "m"}, NumberWithUnits{200, "cm"});
    CHECK_GE(NumberWithUnits{3, "m"}, NumberWithUnits{3000, "mm"});
    CHECK_EQ(NumberWithUnits{2, "m"}, NumberWithUnits{0.002, "km"});
    CHECK_NE(NumberWithUnits{3, "m"}  , NumberWithUnits{5, "km"});

}

TEST_CASE("test * operation"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{1, "cm"};
    NumberWithUnits b{2, "mm"};
    NumberWithUnits c{1, "km"};
    NumberWithUnits d{1, "m"};
    NumberWithUnits e{2, "apple"};
    CHECK((a*2) == NumberWithUnits{2, "cm"});
    CHECK((0.5*b) == NumberWithUnits{1, "mm"});
    CHECK((c*3.5) == NumberWithUnits{3.5, "km"});
    CHECK(c == NumberWithUnits{1, "km"});
}