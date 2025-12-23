#include "Serializer.hpp"
#include <iostream>

int main()
{
    // Create a Data object
    Data original;
    original.name = "Ben";
    original.age = 36;
    original.score = 42.5;

    std::cout << "- Before serialization -" << std::endl;
    std::cout << "Address: " << &original << std::endl;
    std::cout << "Name: " << original.name << std::endl;
    std::cout << "Age: " << original.age << std::endl;
    std::cout << "Score: " << original.score << std::endl;
    std::cout << std::endl;

    // Serialize: pointer → unsigned integer
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "- After serialization -" << std::endl;
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << std::endl;

    // Deserialize: unsigned integer → pointer
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "- After deserialization -" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Score: " << deserialized->score << std::endl;
    std::cout << std::endl;

    std::cout << "- Verification -" << std::endl;
    if (&original == deserialized)
        std::cout << "SUCCESS: Pointers are equal" << std::endl;
    else
        std::cout << "FAILURE: Pointers are different" << std::endl;

    return (0);
}