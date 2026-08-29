NAME = Span
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Span.cpp
OBJ = $(SRC:%.cpp=%.o)
HEADER = Span.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all