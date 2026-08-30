NAME = RPN
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp RPN.cpp
OBJ = $(SRC:%.cpp=%.o)
HADER = RPN.hpp

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o:%.cpp $(HADER)
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all