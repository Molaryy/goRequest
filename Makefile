BASE = src

SRC += $(BASE)/main.cpp

OBJ = $(SRC:.cpp=.o)

SFML = -lsfml-system -lsfml-window -lsfml-graphics

CPPFLAGS = -I includes/ -Wall -Wextra -lm

NAME = goRequest

all: $(OBJ)
	@ g++ -o $(NAME) $(OBJ) $(SFML) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
