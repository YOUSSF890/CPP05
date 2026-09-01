#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "iostream"

class PmergeMe
{
    private:
        int c;
    public:
        void sortVector(std::vector<int>& arr);
        std::vector<std::size_t> generateInsertionOrder(std::size_t size);
};

#endif