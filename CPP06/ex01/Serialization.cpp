#include "Serialization.hpp"

Serializer::Serializer() {};

Serializer::Serializer(const Serializer&) {};

Serializer& Serializer::operator=(const Serializer&)
{
    return (*this);
}

Serializer::~Serializer() {};

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}