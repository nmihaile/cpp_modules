
NAME		=	btc
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11

SRCS		=	main.cpp utils.cpp BitcoinExchange.cpp
OBJS		=	$(SRCS:.cpp=.o)

TNAME		=	btctest
TSRCS		=	test/test.cpp test/tester.cpp utils.cpp BitcoinExchange.cpp
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

t:
	@./$(NAME) t

rt: fclean all t

$(TNAME): $(TOBJS)
	$(CPP) $(CPPFLAGS) $(TOBJS) -o $(TNAME)

test: $(TNAME)
	@./$(TNAME)

.PHONY: all fclean clean test