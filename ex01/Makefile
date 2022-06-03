SRCS			= book.cpp

OBJS			= $(SRCS:.cpp=.o)

CC				= g++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98

NAME			= book

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re