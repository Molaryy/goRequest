BASE = src

ARRAY = $(BASE)/array
FILE = $(BASE)/fi1le
HASH_MAP = $(BASE)/hash_map
INT = $(BASE)/int
LINK = $(BASE)/link
STR = $(BASE)/str
BOOL = $(BASE)/bool

SRC += $(INT)/getNumber.cpp
SRC += $(BOOL)/charIsNum.cpp

OBJ = $(SRC:.cpp=.o)

LIB_NAME = libjb.a

CPPFLAGS = -I../../includes/ -Wall -Wextra -Werror

all: $(OBJ)
	@ar -rc ../$(LIB_NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ../$(LIB_NAME)

re: fclean all
