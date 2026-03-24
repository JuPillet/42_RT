NAME 		=	rt

DIRLIBFT	=	./libft/

DIRMLX		=	./minilibx-linux/

CC			=	g++

rm			=	rm -rf

CFLAGS 		=	-Wall -Wextra -Werror -g -std=c++11

FLAGGLFW	=	-lglfw

INCLUDES	=	./include

SRC			=	$(addprefix ./src/, \
					Engine.cpp \
					main.cpp)

OBJS		=	${SRC:.cpp=.o}

.cpp.o		:
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.cpp=.o}

all			:	${HPROJECT}  ${NAME}

#${LIBFT}	:
#	make -C ${DIRLIBFT}
#	mv ${DIRLIBFT}${LIBFT} ./
#	cp ${DIRLIBFT}${HDLFT} ${INCLUDES}

${NAME}		:	${OBJS}
	${CC} ${CFLAGS} -I$(INCLUDES) ${OBJS} -o ${NAME} ${FLAGGLFW}

#bonus		:	
#	make BONUS=1 all
#
clean		:
	rm -rf ${OBJS}
 
fclean		:	clean
	rm -rf ./${NAME}

re			:	fclean all

.PHONY		:	all bonus clean fclean re