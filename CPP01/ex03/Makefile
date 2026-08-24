NAME = Weapon
CC = c++
CFLAG = -Werror -Wextra -Wall -std=c++98
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = $(SRC:%.cpp=%.o)
HEADER = Weapon.hpp HumanA.hpp HumanB.hpp

all: $(NAME)


%.o: %.cpp $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all