
NAME		=	PmergeMe
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11 -Ofast #-g #-fsanitize=address

SRCS		=	main.cpp VectorPmergeMe.cpp
OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	strip $(NAME)

%.o: %.c
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# TEST_VALUES		=	3
# TEST_VALUES		=	2 1
# TEST_VALUES		=	7 6 5 4 3 2 1
# TEST_VALUES		=	0 1 2 3 4 5 6 7 8 9
# TEST_VALUES		=	12 11 10 9 8 7 6 5 4 3 2 1
# TEST_VALUES		=	11 2 17 0 16 8 6 15 10 3 21 1 18 9
# TEST_VALUES		=	11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
# TEST_VALUES		=	11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
TEST_VALUES		=	14  2 12 15 15 10  2  3 16 15 12  3  8 15 10  0 21  3  4  7 12

t: $(NAME)
	@./$(NAME) $(TEST_VALUES)

rt: re
	@./$(NAME) $(TEST_VALUES)

re: fclean all
