BASE = src

SRC += $(BASE)/main.cpp

OBJ = $(SRC:.cpp=.o)

SFML = -lsfml-system -lsfml-window -lsfml-graphics

CPPFLAGS = -Wall -Wextra -W -I includes/

NAME = goRequest

JB_LIB = -L./lib -ljb

all: $(OBJ)
	@$(MAKE) -sC lib/jb --no-print-directory
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS) $(SFML) $(JB_LIB)


clean:
	@$(MAKE) clean -sC lib/ --no-print-directory
	@rm -f $(OBJ)
	@echo "\e[33mclean done\e[0m"

fclean: clean
	@$(MAKE) fclean -sC lib/ --no-print-directory
	@ rm -f $(NAME)
	@ rm -f a.out
	@echo "\e[1;31mfclean done\e[0m"

re: fclean all
