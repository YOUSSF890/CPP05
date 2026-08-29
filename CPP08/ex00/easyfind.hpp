#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>

int easyfind(T &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::runtime_error("value not found");
    return (*it);
}

#endif
