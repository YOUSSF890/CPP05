#include "Serialization.hpp"


int main()
{
    Data *ptr = new Data;
    ptr->i = 43;

    std::cout << "ptr->i = " << ptr->i << std::endl;
    std::cout << "ptr = " << ptr << std::endl;
    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "raw = " << raw << std::endl;
    Data *ptr2 = Serializer::deserialize(raw);
    std::cout << "ptr2 = " << ptr2 << std::endl;
    std::cout << "ptr2->i = " << ptr2->i << std::endl;
    ptr->i = 999999;
    std::cout << "ptr2->i = " << ptr2->i << std::endl;
}