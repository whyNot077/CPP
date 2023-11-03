CXXFLAGS		= -Wall -Wextra -Werror -MMD -std=c++98
NAME			= PmergeMe
RM				= rm -f

EXEC            = PmergeMe
SOURCES			= $(wildcard *.cpp)
OBJECTS         = $(SOURCES:.cpp=.o)

HEADER          = $(wildcard *.hpp)

ifdef DEBUG
	CXXFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)
	@echo -e "$(GREEN)$(EXEC) created!$(DEFAULT)"

%.o: %.cpp $(HEADER)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJECTS)
	@$(RM) $(OBJECTS:.o=.d)

fclean: clean
	@$(RM) $(EXEC)
	@echo -e "$(BLUE)delete all!$(DEFAULT)"

re:
	@make fclean
	@make all
	
debug: fclean
	make DEBUG=1 -j

test: all
	./PmergeMe `jot -r 20 1 100000 | tr '\n' ' '`

.PHONY: all clean fclean re debug

-include $(wildcard *.d)

RED = \033[1;31m
PINK = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
DEFAULT = \033[0m
