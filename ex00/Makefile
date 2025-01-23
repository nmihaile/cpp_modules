
NAME		=	btc
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11

SRCS		=	main.cpp utils.cpp BitcoinExchange.cpp
OBJS		=	$(SRCS:.cpp=.o)

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

t:
	@./$(NAME)

rt: fclean all t
