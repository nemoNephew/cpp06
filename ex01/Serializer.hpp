#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
// #include <cstdlib>
// #include <cctype>
#include <stdint.h>


typedef struct Data_s {
    std::string name;
    int age;
} Data;

class Serializer
{
    private:
        Serializer() {}
        Serializer(Serializer& obj) {(void)obj;}
        Serializer& operator=(Serializer& obj) {(void)obj;return *this;}
        ~Serializer() {}
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif

