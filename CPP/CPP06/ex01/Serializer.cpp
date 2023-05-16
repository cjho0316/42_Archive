#include "Serializer.hpp"

/* OCF */
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &copy) { (void)copy; }
Serializer::~Serializer() {}
Serializer &Serializer::operator=(const Serializer &copy) {
    (void)copy;
    return (*this);
}

/* member functions */
uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}