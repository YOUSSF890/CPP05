NAME = phonebook
CC = c++
FLAG = -Werror -Wextra -Wall -std=c++98
SRC =Contact.cpp PhoneBook.cpp main.cpp 
OBJ = $(SRC:%.cpp=%.o)
HEADER = PhoneBook.hpp Contact.hpp

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all
