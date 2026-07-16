NAME = Bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC = src/Bureaucrat.cpp \
		src/AForm.cpp src/main.cpp \
		src/ShrubberyCreationForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/PresidentialPardonForm.cpp

OBJ = $(SRC:src/%.cpp=%.o)

all: $(NAME)

$(NAME):  $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
