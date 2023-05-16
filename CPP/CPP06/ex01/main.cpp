#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {

    Data* originalData = new Data(42, "John Doe");
	std::cout << "Original data: " << originalData << std::endl;


    uintptr_t serializedPtr = Serializer::serialize(originalData);
	std::cout << "Serialized data: " << serializedPtr << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedPtr);
	std::cout << "Deserialized data: " << deserializedData << std::endl;

	std::cout << "-------------------------------------" << std::endl;

    if (deserializedData == originalData) {
        std::cout << "Deserialization successful. Pointers match!" << std::endl;
    } else {
        std::cout << "Deserialization failed. Pointers do not match!" << std::endl;
    }

    delete originalData;

    return 0;
}