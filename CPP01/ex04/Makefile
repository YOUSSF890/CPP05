NAME = file_replace
CC = c++
CFLAG = -Werror -Wextra -Wall -std=c++98
SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $<  -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all