NAME = push_swap

BONUS_NAME = checker

INC = -I includes/ -I libft/includes

CFLAGS = -Wall -Wextra -Werror

OBJ = obj/*.o

BONUS_OBJ = bonus_obj/*.o

LIBFT = libft/libft.a

all:	${LIBFT} ${OBJ}
	@gcc ${CFLAGS} -o ${NAME} ${LIBFT} ${OBJ}
	@echo "\n🎊 Programa creado 🎊\n"

${LIBFT}:	libft/src/*.c
	@make -C libft/ --silent
	@echo "\n📕 Libft compilada ✅\n"

${OBJ}:	src/*.c
	@gcc ${INC} ${CFLAGS} -c src/*.c
	@mkdir obj
	@mv *.o obj
	@echo "\n🔨 Objetos creados ✅\n"

${BONUS_OBJ}:	src_bonus/*.c
	@gcc ${INC} ${CFLAGS} -c src_bonus/*.c
	@mkdir bonus_obj
	@mv *.o bonus_obj
	@echo "\n🔨 Objetos bonus creados ✅\n"

clean:
	@make -C libft/ clean --silent
	@rm -rf obj
	@rm -rf bonus_obj
	@echo "\n🧨 Objetos destruidos ✅\n"

fclean: clean
	@make -C libft/ fclean --silent
	@rm -f ${NAME}
	@rm -f ${BONUS_NAME}
	@echo "\n💥 Archivos binarios destruidos ✅\n"

sclean: fclean
	@rm -f *.o

re: fclean all

sre: sclean all

bonus: ${LIBFT} ${BONUS_OBJ}
	@gcc ${CFLAGS} -o ${BONUS_NAME} ${LIBFT} ${BONUS_OBJ}
	@echo "\n🎊 Programa bonus creado 🎊\n"

.PHONY: bonus all clean fclean sclean re sre
