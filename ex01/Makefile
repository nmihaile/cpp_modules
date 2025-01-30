
NAME		=	RPN
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11

SRCS		=	main.cpp RPN.cpp
OBJS		=	$(SRCS:.cpp=.o)

TNAME		=	testRPN
TSRCS		=	test/test.cpp test/tester.cpp RPN.cpp
TOBJS		=	$(TSRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

t: $(NAME)
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

rt: fclean all t

$(TNAME): $(TOBJS)
	$(CPP) $(CPPFLAGS) $(TOBJS) -o $(TNAME)

test: $(TNAME)
	@./$(TNAME)

.PHONY: all fclean clean test