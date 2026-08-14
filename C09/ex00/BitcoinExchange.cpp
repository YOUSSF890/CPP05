#include "BitcoinExchange.hpp"

// 2009-01-02,0

void check_date(std::string date)
{
    std::string year;
    std::string month;
    std::string day;
    std::string str = "";
    int count = 0;
    for(size_t i = 0; i < date.size();i++)
    {
        if (date[i] == '-')
        {
            count++;
            if (count == 1)
                year = str;
            else if (count == 2)
                month = str;
            str = "";
        }
        else
            str += date[i];
    }
    day = str;
    if(std::atoi(year.c_str()) > 2026 || std::atoi(year.c_str()) < 2009
        || std::atoi(month.c_str()) > 12 || std::atoi(month.c_str()) < 1
        || std::atoi(day.c_str()) > 31 || std::atoi(day.c_str()) < 1)
    { 
        throw std::runtime_error("error: date in file data.cvs");
    }
}



void Bitcoin::readInputFile()
{
    std::ifstream file("data.csv");

    if (!file.is_open())
        throw std::runtime_error("Error: could not open data.csv.");
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
    {
        auto it = std::find(line.begin(), line.end(), ',');

        std::string s_date = line.substr(0,it - line.begin());
        std::string s_value = line.substr(it - line.begin(),line.end() - line.begin());
        s_value.erase(s_value.begin());
        data[s_date] = s_value;
        check_date(s_date);
        std::cout << "date = "<< s_date << std::endl;
        std::cout << "vlaue = "<< s_value << std::endl;

    }
}