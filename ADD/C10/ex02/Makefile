SRCS = 	ft_tail.c check_args.c print.c stdin.c

OBJS = 	${SRCS:%.c=%.o}

NAME = 	ft_tail

CC 	= 	gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	 rm -rf ${OBJS}

fclean: clean
	 ${RM} ${NAME}