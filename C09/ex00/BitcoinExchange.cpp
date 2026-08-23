#include "BitcoinExchange.hpp"



bool check_date(std::string date)
{
    int year;
    int month;
    int day;
    int count = 0;
    for (size_t i = 0; i < date.size();i++)
    {
        if (date[i] == '-')
            count++;
        if (!isdigit(date[i]) && (date[i] != '-' || count > 2))
            return false;
        
    }

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::stringstream ss(date);
    char dash;
    ss >> year >> dash >> month >> dash >> day;

    int array_days_ofmonth[] = {31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (year < 2009 || (year < 2009 && day < 2))
        return false;
    else if (month < 1 || month > 12)
        return false;
    else if (day < 1 || day > 31)
        return false;
    
    
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        array_days_ofmonth[1] = 29;
    if (array_days_ofmonth[month - 1] < day)
        return (false);
    return true;
}

bool check_value(double value)
{
    if (value > 1000)
        std::cout << "Error: too large a number." << std::endl;
    else if (value < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else
        return true;
    return false;
}

void Bitcoin::printTotal(std::string date, double value)
{
    std::map<std::string, double>::iterator it = data.lower_bound(date);

    if (it != data.begin() && date != it->first)
        --it;
    std::cout << date << " => " << value << " = " << data[it->first] * value << std::endl;
}

void Bitcoin::readFileData()
{
    std::string s_date;
    std::string line;
    double value;

    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data.csv.");

    std::getline(file, line);
    
    while(std::getline(file, s_date,','))
    {
        std::getline(file, line);
        std::stringstream ss(line);
        ss >> value;
        data[s_date] = value;
    }
}


void Bitcoin::readInputFile(std::string name_file)
{
    std::ifstream file(name_file.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line);
    if (line != "date | value")
        throw std::runtime_error("Error: start line in date | value");
    while (std::getline(file,line))
    {
        std::string s_date;
        char l;
        double value;
        std::stringstream str(line);

        str >> s_date;
        if (str.fail())
        {
            std::cout << "Error: bad input => 'date'" << std::endl;
            continue;
        }
        str >> l;
        if (str.fail())
        {
            std::cout << "Error: bad input => " << s_date << std::endl;
            continue;
        }
        else if(l != '|')
        {
            std::cout << "Error: bad input => '|'" << std::endl;
            continue;
        }
        str >> value;
        if (str.fail() || std::getline(str,line))
        {
            std::cout << "Error: bad input => 'value'" << std::endl;
            continue;
        }

        if (!check_value(value))
            continue;
        if (!check_date(s_date))
        {
            std::cout << "Error: bad input => " << s_date << std::endl;
            continue;
        }
        printTotal(s_date,value);
    }
}