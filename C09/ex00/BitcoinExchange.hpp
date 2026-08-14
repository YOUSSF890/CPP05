#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>

#include <map>

class Bitcoin
{
    private:
        std::map<std::string, std::string> data;
    public:
        void readInputFile();
        // void check_date();
};

#endif