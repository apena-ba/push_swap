NAME = libft.a

SRC = src/*.c

OBJ =  obj/*.o

GCC = gcc

CFLAGS = -Wall -Werror -Wextra -I./includes

all: ${NAME}

$(NAME): ${OBJ}
	@ar rcs ${NAME} ${OBJ}

$(OBJ):	${SRC}
	@${GCC} ${CFLAGS} -c ${SRC}
	@mkdir obj
	@mv *.o obj

clean:
	@rm -rf obj

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
