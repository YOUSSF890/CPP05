#include "RPN.hpp"


void RPN::StoreElement()
{
    std::string c;
    int a;
    int b;
    int Result;
    std::stringstream ss(str);
    while(ss >> c)
    {
        if (ss.fail() || c.size() > 1)
            throw std::runtime_error("Error : 1");
        if (c[0] >= '0' && c[0] <= '9')
            stack.push(c[0] - '0');
        else
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error : 2");
            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();
            if (c[0] == '+')
            {
                if (a + static_cast<long>(b) > INT_MAX || a + static_cast<long>(b) < INT_MIN)
                    throw std::runtime_error("Error : 6");
                Result = a + b;
            }
            else if (c[0] == '-')
            {
                if (a - static_cast<long>(b) > INT_MAX || a - static_cast<long>(b) < INT_MIN)
                    throw std::runtime_error("Error : 7");
                Result = a - b;
            }
            else if (c[0] == '/')
            {
                if (b == 0 || a / static_cast<long>(b) > INT_MAX)
                    throw std::runtime_error("Error : 4");
                Result = a / b;
            }
            else if (c[0] == '*')
            {
                if (a * static_cast<long>(b) > INT_MAX || a * static_cast<long>(b) < INT_MIN)
                    throw std::runtime_error("Error : 9");
                Result = a * b;
            }
            else
                throw std::runtime_error("Error : 5");
            stack.push(Result);
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error : 3");
}