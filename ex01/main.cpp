#include "Serializer.hpp"

int main()
{
    Data* data = new Data;
    data->name = "John Doe";
    data->age = 30;

    std::cout << "Original Data: " << data->name << ", " << data->age << std::endl;

    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "Serialized Data (uintptr_t): " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data: " << deserialized->name << ", " << deserialized->age << std::endl;

    delete data;
    return 0;
}