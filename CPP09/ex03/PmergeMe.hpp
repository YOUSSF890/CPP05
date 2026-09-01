#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include <cstdlib>//dellet

class PmergeMe
{
    private:
        int c;
    public:
        
        std::vector<std::size_t> generateInsertionOrder(std::size_t size);
};
void sortVector(std::vector<int>& arr);
#endif