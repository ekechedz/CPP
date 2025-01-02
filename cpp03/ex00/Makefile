# Compiler and flags
CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

# Targets
NAME = claptrap
SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
