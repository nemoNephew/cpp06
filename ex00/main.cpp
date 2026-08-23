#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter::converter("c");
    ScalarConverter::converter("42");
    ScalarConverter::converter("4.25f");
    ScalarConverter::converter("4.25");
    ScalarConverter::converter("nan");
    ScalarConverter::converter("nanf");
    ScalarConverter::converter("+inf");
    ScalarConverter::converter("-inf");
    ScalarConverter::converter("+inff");
    ScalarConverter::converter("-inff");
    ScalarConverter::converter("");
    ScalarConverter::converter("0");
    ScalarConverter::converter("0.0");
    ScalarConverter::converter("0.0f");
    ScalarConverter::converter("0.15.7f");
    ScalarConverter::converter("dhf");
}