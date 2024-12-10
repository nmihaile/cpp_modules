NAME		=	main
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11

SRCS		=	main.cpp Bureaucrat.cpp
OBJS		=	$(SRCS:.cpp=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all