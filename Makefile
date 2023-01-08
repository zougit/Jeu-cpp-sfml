CC = g++
RM = rm -f
NAME = jeu
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -lm -o $(NAME) -Werror -lsfml-graphics -lsfml-window -lsfml-system
	$(RM) $(OBJS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re