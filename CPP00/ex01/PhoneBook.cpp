#include "PhoneBook.hpp"

void PhoneBook::ft_table()
{
    int a;

	a = 0;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	while (a < N)
	{
		std::cout << "|         " << a;
		contact[a].printTable();
		std::cout << "|\n";
		a++;
	}
}

void PhoneBook::ft_phonebook()
{
	i = 0;
	B = 0;
	std::string str1;
    while (1)
    {
		std::cout << "commands : ADD or SEARCH or EXIT \n";
		if (!std::getline(std::cin, str))
			std::exit(1);
        if (str == "ADD")
		{
			if (contact[i].add_contact())
				i--;
			i++;
			if (i == SIZE)
			{
				B = 1;
				i = 0;
			}
		}
        else if (str == "SEARCH")
		{
			N = i;
			if (B == 1)
				N = SIZE;
			if (N == 0) 
				std::cout << "[   EMPTY   ]\n";
			else
            {
	            ft_table();
	            std::cout << "index : ";
	            if (!std::getline(std::cin, str1))
					std::exit(1);
	            if (std::atoi(&str1[0]) < N && std::isdigit(str1[0]) && str1[1] == '\0')
	            {
		            contact[std::atoi(&str1[0])].print_contact();
	            }
	            else
		            std::cout << "invalid index\n";
            }
		}
		else if (str == "EXIT")
			break ;
    }
}