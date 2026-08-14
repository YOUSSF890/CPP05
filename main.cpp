#include <iostream>



int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    

    numbers.insert(numbers.begin(), 5);

//   std::vector<int>::iterator it = numbers.begin();

    // numbers.pop_back();
    // numbers.pop_back();
    // numbers.pop_back();
    // numbers.push_back(12);
    size_t i=  numbers.end() -numbers.begin();
    std::cout << i << std::endl;
    // std::cout << *it << std::endl;
    // ++it;
    // std::cout << *it << std::endl;
}