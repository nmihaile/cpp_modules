
NAME		= tests
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= Account.cpp tests.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
