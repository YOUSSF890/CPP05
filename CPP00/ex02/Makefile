NAME = Account
CC = c++
FLAG = -Werror -Wextra -Wall -std=c++98
SRC = tests.cpp Account.cpp
OBJ = $(SRC:%.cpp=%.o)
HEADER = Account.hpp

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



