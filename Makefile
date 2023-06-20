NAME        := push_swap
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 

SRCS        :=      list_utils.c push_swap_utils.c push_swap.c radix_utils.c sort_utils.c sorts.c
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
