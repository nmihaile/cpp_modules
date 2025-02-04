
NAME		=	PmergeMe
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11

SRCS		=	main.cpp PmergeMe.cpp VectorPmergeMe.cpp
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

# TEST_VALUES		=	11 2 17 0 16 8 6 15 10 3 21 1 18 9
TEST_VALUES		=	11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

t: $(NAME)
	@./$(NAME) $(TEST_VALUES)

rt: re
	@./$(NAME) $(TEST_VALUES)

re: fclean all
