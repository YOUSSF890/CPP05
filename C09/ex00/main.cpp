#include "BitcoinExchange.hpp"



int main(int ac, char *av[])
{
    try
    {
        Bitcoin btc;
        if (ac != 2)
            throw std::runtime_error("Error: could not open file.");
        btc.readFileData();
        btc.readInputFile(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}