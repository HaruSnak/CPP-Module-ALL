//#include "../includes/Data.hpp"
#include "../includes/Serializer.hpp"

int main()
{
    Data original;
    original.value = 42;
    original.name = "Test Object";

    std::cout << "Original address: " << &original << std::endl;
    std::cout << "Original values: " << original.value << ", " << original.name << std::endl;

    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;
	
    if (deserialized == &original)
	{
        std::cout << "\nSUCCESS: Pointers match!" << std::endl;
        std::cout << "Deserialized values: " << deserialized->value << ", " << deserialized->name << std::endl;
    }
	else 
        std::cout << "\nERROR: Pointers don't match!" << std::endl;
    return (0);
}