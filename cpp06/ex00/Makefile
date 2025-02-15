
NAME		=	convert
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11

SRCS		=	main.cpp ScalarConverter.cpp
OBJS		=	$(SRCS:.cpp=.o)

TNAME		=	test
TSRCS		=	tester.cpp ScalarConverter.cpp
TOBJS		=	$(TSRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(TOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TNAME)

re: fclean all

test: $(TOBJS)
	@$(CPP) $(CPPFLAGS) $(TOBJS) -o $(TNAME)

t: test
	@./$(TNAME)