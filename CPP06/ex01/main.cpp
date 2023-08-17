#include "includes.hpp"

int main() {
    Data* data1 = new Data;
    data1->s1 = "Hello";
    data1->n = 42;
    data1->s2 = "World";

    std::cout << "Serializing and Deserializing data1:\n";
    std::cout << "Original pointer: " << BLUE << data1 << DEFAULT << "\n";
    unsigned long long raw1 = Serializer::serialize(data1);
    std::cout << "Serialized (raw) pointer: " << raw1 << "\n";
    Data* deserializedData1 = Serializer::deserialize(raw1);
    std::cout << "Deserialized pointer: " << deserializedData1 << "\n";
    std::cout << "Original s1: " << data1->s1 << " - Deserialized s1: " << deserializedData1->s1 << "\n";
    std::cout << "Original n: " << data1->n << " - Deserialized n: " << deserializedData1->n << "\n";
    std::cout << "Original s2: " << data1->s2 << " - Deserialized s2: " << deserializedData1->s2 << "\n";

    std::cout << "\nTesting with null pointer:\n";
    Data* nullData = NULL;
    unsigned long long rawNull = Serializer::serialize(nullData);
    Data* deserializedNull = Serializer::deserialize(rawNull);
    if (deserializedNull == NULL) {
        std::cout << "Successfully handled null pointer.\n";
    } else {
        std::cout << "Null pointer test failed.\n";
    }

    delete data1;
    return 0;
}
