NAME        = form
SRCS        = main.cpp Bureaucrat.cpp AForm.cpp \
              ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ_DIR     = obj
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS        = $(OBJS:.o=.d)

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
DEPFLAGS    = -MMD -MP
RM          = rm -f

all:        $(NAME)

$(NAME):    $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(GREEN)Successfully compiled $(NAME)!$(RESET)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@$(RM) *_shrubbery

fclean:     clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re:         fclean all

-include $(DEPS)

GREEN       = \033[1;32m
RED         = \033[1;31m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
RESET       = \033[0m

.PHONY:     all clean fclean re