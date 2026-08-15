#include "BitcoinExchange.hpp"

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
        std::cout << "sss" << year << std::endl;
        std::cout << "sss" << month << std::endl;
        std::cout << "sss" << day << std::endl;
        throw std::runtime_error("error: date in file data.cvs");
    }
}

void check_value(std::string value)
{
    if (std::atoi(value.c_str()) > 1000 || std::atoi(value.c_str()) < 0)
        throw std::runtime_error("error: in value");
}

void Bitcoin::printTotal(std::string date,std::string value)
{
    std::cout << data[date] << std::endl;
}

void Bitcoin::readFileData()
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
        check_date(s_date);
        data[s_date] = s_value;
    }
}


void Bitcoin::readInputFile(std::string name_file)
{
    std::ifstream file(name_file);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    while (std::getline(file,line))
    {
        auto it = std::find(line.begin(), line.end(), '|');
        std::string s_date = line.substr(0,it - line.begin());
        std::string s_value = line.substr(it - line.begin(),line.end() - line.begin());
        s_date.erase(s_date.begin(),s_date.end());
        s_value.erase(s_value.begin()+0);
        s_value.erase(s_value.begin()+0);
        // std::cout << "s_value=" << s_value << std::endl;
        check_value(s_value);
        check_date(s_date);
        printTotal(s_date,s_value);
    }
}