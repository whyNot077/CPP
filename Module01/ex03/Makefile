CC              = c++ -std=c++98
CFLAGS          = -Wall -Wextra -Werror -MMD
NAME            = zombie
RM              = rm -f

EXEC            = zombie
SOURCES			= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJECTS         = $(SOURCES:.cpp=.o)

HEADER          = HumanA.hpp HumanB.hpp Weapon.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)
	@echo -e "$(GREEN)$(EXEC) created!$(DEFAULT)"

%.o: %.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJECTS)
	@$(RM) $(OBJECTS:.o=.d)

fclean: clean
	@$(RM) $(EXEC)
	@echo -e "$(BLUE)delete all!$(DEFAULT)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re

-include $(OBJECTS:.o=.d)

RED = \033[1;31m
PINK = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
DEFAULT = \033[0m