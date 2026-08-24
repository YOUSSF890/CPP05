#include "Contact.hpp"

void Contact::setFirstName(std::string str)
{
	firstName = str;
}
void Contact::setLastName(std::string str)
{
	lastName = str;
}
void Contact::setNickname(std::string str)
{
	nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
	phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
	darkestSecret = str;
}


std::string Contact::getFirstName()
{
	return (firstName);
}
std::string Contact::getLastName()
{
	return (lastName);
}
std::string Contact::getNickname()
{
	return (nickname);
}

std::string Contact::getPhoneNumber()
{
	return (phoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (darkestSecret);
}

void printName(std::string st)
{
	int i = 0;
	int n;

	n = st.size();
	std::cout << "|";
	if (n > 10)
	{
		while (i < 9)
			std::cout << st[i++];
		std::cout << ".";
	}
	else if (n <= 10)
	{
		std::cout << std::setw(10) << st;
	}
	
}

void Contact::printTable()
{
    printName(getFirstName());
	printName(getLastName());
	printName(getNickname());
}

int chick_digit(std::string digit)
{
	int i;

	i = 0;
	if (!digit[i])
		return (1);
	while (digit[i])
	{
		if (!std::isdigit(digit[i]))
			return (1);
		i++;
	}
	return (0);
}

void Contact::print_contact()
{
	std::cout << "firstName = " << getFirstName() << std::endl;
	std::cout << "lastName = " << getLastName() << std::endl;
	std::cout << "nickname = " << getNickname() << std::endl;
	std::cout << "phoneNumber = " << getPhoneNumber() << std::endl;
	std::cout << "darkestSecret = " << getDarkestSecret() << std::endl;
}

int ft_isprintable(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (!std::isprint(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int Contact::add_contact()
{
	std::string name1;
	std::string name2;
	std::string name3;
	std::string name4;
	std::string name5;

	std::cout << "first name : ";
	if (!std::getline(std::cin, name1))
		std::exit(1);
	if(name1 == "\0" || ft_isprintable(name1))
		return (std::cout << "invalid firstName\n", 1);

	std::cout << "last name : ";
	if (!std::getline(std::cin, name2))
		std::exit(1);
	if(name2 == "\0" || ft_isprintable(name2))
		return (std::cout << "invalid lastName\n",1);

	std::cout << "nickname : ";
	if (!std::getline(std::cin, name3))
		std::exit(1);
	if(name3 == "\0" || ft_isprintable(name3))
		return (std::cout << "invalid nickname\n", 1);

	std::cout << "phone number : ";
	if (!std::getline(std::cin, name4))
		std::exit(1);
	if (chick_digit(name4) || ft_isprintable(name4))
		return (std::cout << "invalid phoneNumber\n", 1);

	std::cout << "darkest secret : ";
	if (!std::getline(std::cin, name5))
		std::exit(1);
	if(name5 == "\0" || ft_isprintable(name5))
		return (std::cout << "invalid darkestSecret\n", 1);

	setFirstName(name1);
	setLastName(name2);
	setNickname(name3);
	setPhoneNumber(name4);
	setDarkestSecret(name5);
	return (0);
}