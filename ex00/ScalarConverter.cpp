#include "ScalarConverter.hpp"


static bool isDisplayable(char c) {
    return std::isprint(static_cast<unsigned char>(c));
}

static bool isChar(std::string str)
{   
    if (str.length() == 1)
    {
        if (isDisplayable(str[0]) && !std::isdigit(str[0]))
            return true;
    }
    return false;
}

static bool isInt(std::string str)
{
    int i = 0;
    int limit = str.length();
    while (i < limit) {
        if (i == 0 && str[0] == '-')
            i++;
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

static bool checkDot(std::string str)
{
    int i = 0;
    int whereDot = -1;
    int count = 0;
    int limit = str.length();
    while (i < limit) {
        if (i == 0 && str[0] == '-')
            i++;
        if (str[i] == '.')
        {
            whereDot = i;
            count++;
        }
        else if (!(str[i] == 'f' && i == limit - 1) && !std::isdigit(str[i]))
            return false;
        i++;
    }
    if (count == 1 && whereDot > 0 && whereDot < limit - 1)
        if (std::isdigit(str[whereDot - 1]) && std::isdigit(str[whereDot + 1]))
            return true;
    
    return false;
}

static bool isFloat(std::string str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    if (str[str.length() - 1] != 'f' || !checkDot(str))
        return false;
    return true;
}

static bool isDouble(std::string str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    if (!checkDot(str))
        return false;
    return true;
}

static int isWhat(std::string str)
{
    if (isChar(str))
        return 1;
    else if (isInt(str))
        return 2;
    else if (isFloat(str))
        return 3;
    else if (isDouble(str))
        return 4;
    else
        return 0;
}

void ScalarConverter::converter(std::string str)
{
    if (isWhat(str) == 0)
        std::cout << "Error: Invalid input" << std::endl;
    else if (isWhat(str) == 1) {
        std::cout << "char: " << str << "\n";
        int i = static_cast<int>(str[0]);
        std::cout << "int: " << i << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(i) << std::endl;
    }
    else if (isWhat(str) == 2) {
        char** ptr = NULL;
        errno = 0;
        long val = strtol(str.c_str(), ptr, 10);
        if (errno == ERANGE || val > INT_MAX || val < INT_MIN) {
            std::cout << "char: Impossible\n";
            std::cout << "int: Impossible\n";
            std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(val) << "f\n";
            std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(val) << std::endl;
        }
        else {
            int i = static_cast<int>(val);
            if (i > 31 && i < 127)
                std::cout << "char: " << static_cast<unsigned char>(i) << '\n';
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << i << "\n";
            std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f\n";
            std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(i) << std::endl;
        }
    }
    else if (isWhat(str) == 3) {
        if (str == "nanf" || str == "+inff" || str == "-inff") {
            std::cout << "char: Impossible\n";
            std::cout << "int: Impossible\n";
            std::cout << "float: " + str + '\n';
            std::cout << "double: ";
            int i = 0;
            int limit = str.length() - 1;
            while (i < limit)
                std::cout << str[i++];
            std::cout << std::endl;
        }
        else {
            char** ptr = NULL;
            float f = static_cast<float>(strtod(str.c_str(), ptr));
            if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN)) {
                std::cout << "char: Impossible\n";
                std::cout << "int: Impossible\n";
            } 
            else {
                int i = static_cast<int>(f);
                if (i > 31 && i < 127)
                    std::cout << "char: " << static_cast<unsigned char>(i) << '\n';
                else
                    std::cout << "char: Non displayable\n";
                std::cout << "int: " << i << "\n";
            }
            std::cout << "float: " << std::fixed << std::setprecision(2) << f << "f\n";
            std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(f) << std::endl;
        }
    }
    else if (isWhat(str) == 4) {
        if (str == "nan" || str == "+inf" || str == "-inf") {
            std::cout << "char: Impossible\n";
            std::cout << "int: Impossible\n";
            std::cout << "float: " + str + "f\n";
            std::cout << "double: " + str << std::endl;
        }
        else {
            char** ptr = NULL;
            double d = strtod(str.c_str(), ptr);
            if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN)) {
                std::cout << "char: Impossible\n";
                std::cout << "int: Impossible\n";
            } 
            else {
                int i = static_cast<int>(d);
                if (i > 31 && i < 127)
                    std::cout << "char: " << static_cast<unsigned char>(i) << '\n';
                else
                    std::cout << "char: Non displayable\n";
                std::cout << "int: " << i << "\n";
            }
            if (d > static_cast<double>(FLT_MAX))
                std::cout << "float: +inff\n";
            else if (d < -static_cast<double>(FLT_MAX))
                std::cout << "float: -inff\n";
            else 
                std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f\n";
            std::cout << "double: " << std::fixed << std::setprecision(2) << d << std::endl;
        }
    }
}

// void ScalarConverter::converter(std::string str)
// {
//     const char* s = str.c_str();
//     char c = static_cast<char>(*s);

//     char **ptr = NULL;
//     int i = static_cast<int>(strtol(str.c_str(),ptr,10));
//     char a = static_cast<char>(i);
//     float f = static_cast<float>(strtod(str.c_str(), ptr));
//     double d = strtod(str.c_str(), ptr);
//     std::cout << "char: " << a << "||" << c << std::endl;
//     std::cout << "int: " << i << std::endl;
//     std::cout << "float: " << f << std::endl;
//     std::cout << "double: " << d << std::endl;
// }
