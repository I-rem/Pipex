NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c

OBJS = pipex.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) ar -rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
