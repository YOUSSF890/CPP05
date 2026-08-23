#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#include <map>

class Bitcoin
{
    private:
        std::map<std::string, double> data;
    public:
        void readFileData();
        void readInputFile(std::string name_file);
        void printTotal(std::string date,double value);
};

#endif