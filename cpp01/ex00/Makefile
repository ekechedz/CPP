SRC = newZombie.cpp randomChump.cpp main.cpp Zombie.cpp	

OBJ = $(SRC:.cpp=.o)

NAME = zombie

all: $(NAME)

$(NAME): $(OBJ)
	c++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re