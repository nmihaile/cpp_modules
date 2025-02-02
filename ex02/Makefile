
NAME		=	PmergeMe
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11

SRCS		=	main.cpp PmergeMe.cpp
OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

TEST_VALUES	=	5 4294967295 4 3 2 1

t: $(NAME)
	@./$(NAME) $(TEST_VALUES)

rt: re
	@./$(NAME) $(TEST_VALUES)

re: fclean all
