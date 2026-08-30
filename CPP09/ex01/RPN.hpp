#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <climits>

class RPN
{
    public:
        std::stack<int> stack;
        std::string str;
        void StoreElement();
};


#endif