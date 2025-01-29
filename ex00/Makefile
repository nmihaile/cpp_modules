
NAME		=	btc
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -Ofast -std=c++11

SRCS		=	main.cpp BitcoinExchange.cpp Date.cpp MonetaryValue.cpp
OBJS		=	$(SRCS:.cpp=.o)

TNAME		=	btctest
TSRCS		=	test/test.cpp test/tester.cpp BitcoinExchange.cpp Date.cpp MonetaryValue.cpp
TOBJS		=	$(TSRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@strip $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(TOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TNAME)

re: fclean all

t: $(NAME)
	@./$(NAME) input.txt

rt: fclean all t

$(TNAME): $(TOBJS)
	$(CPP) $(CPPFLAGS) $(TOBJS) -o $(TNAME)

test: $(TNAME)
	@./$(TNAME)

.PHONY: all fclean clean test