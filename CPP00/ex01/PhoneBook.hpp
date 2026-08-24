#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define SIZE 8
#include "Contact.hpp"


class PhoneBook 
{

	private:
		int      i;
		int      N;
		int      B;
		std::string str;
		Contact  contact[SIZE];
		void ft_table(void);
	public:
		void ft_phonebook(void);


};


#endif