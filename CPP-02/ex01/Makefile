NAME        = fixed
SRCS        = main.cpp Fixed.cpp
OBJS        = $(SRCS:.cpp=.o)
DEPS        = $(OBJS:.o=.d)

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
DEPFLAGS    = -MMD -MP
RM          = rm -f

all:        $(NAME)

$(NAME):    $(OBJS)
	@echo "$(BLUE)🎉 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(GREEN)🚀 Successfully compiled $(NAME)!$(RESET)"

%.o:        %.cpp
	@echo "$(BLUE)🔧 Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@$(RM) $(OBJS) $(DEPS)

fclean:     clean
	@echo "$(YELLOW)💥 Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re:         fclean all

-include $(DEPS)

GREEN       = \033[1;32m
RED         = \033[1;31m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
RESET       = \033[0m

.PHONY:     all clean fclean re