#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include <climits>
#include <cerrno>
#include <cfloat>

class ScalarConverter {
    private:
        ScalarConverter(){}
        ScalarConverter(ScalarConverter& obj){(void)obj;}
        ScalarConverter& operator=(ScalarConverter& obj){(void)obj;return *this;}
        ~ScalarConverter(){}
    public:
        static void converter(std::string str);
};

#endif
