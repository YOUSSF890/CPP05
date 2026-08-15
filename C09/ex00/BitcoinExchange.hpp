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
        void readFileData();
        void readInputFile(std::string name_file);
        void printTotal(std::string date,std::string value);
};

#endif