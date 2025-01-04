
NAME		=	convert
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11

SRCS		=	main.cpp ScalarConverter.cpp
OBJS		=	$(SRCS:.cpp=.o)

TNAME		=	test
TSRCS		=	test.cpp
TOBJS		=	$(TSRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(TOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TNAME)

re: fclean all

test: $(TOBJS)
	@$(CC) $(CPPFLAGS) $(TOBJS) -o $(TNAME)

t: test
	@./$(TNAME)