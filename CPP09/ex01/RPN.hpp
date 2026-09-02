#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
#include <stack>
#include <sstream>
#include <climits>

class RPN
{
    public:
        std::stack<int, std::list<int> > stack;
        std::string str;
        void StoreElement();
};


#endif