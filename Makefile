NAME 		=	rt

LIBFT		=	libft.a

HDLFT		=	libft.h

DIRLIBFT	=	./libft/

DIRMLX		=	./minilibx-linux/

CC			=	g++

rm			=	rm -rf

CFLAGS 		=	-Wall -Wextra -Werror -g -std=c++11

FLAGGLFW	=	-lglfw

INCLUDES	=	./includes

SRCS		=	$(addprefix ./SRCS/, \
					engine.cpp \
					main.cpp)

OBJSSRCS	=	${SRCS:.c=.o}

.c.o		:
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

all			:	${HPROJECT}  ${NAME}

#${LIBFT}	:
#	make -C ${DIRLIBFT}
#	mv ${DIRLIBFT}${LIBFT} ./
#	cp ${DIRLIBFT}${HDLFT} ${INCLUDES}

${NAME}		:
	${CC} ${CFLAGS} -I$(INCLUDES) ${OBJSSRCS} -o ${NAME} ${FLAGGLFW}

#bonus		:	
#	make BONUS=1 all
#
# clean		:
# 	rm -rf	
# 
# fclean		:	clean
# 	make fclean -C ${DIRLIBFT}
# 	rm -rf	${NAME} ${NAMELIN} ${NAMEMPRSR} ${NAMELPRSR} ${INCLUDES}${HDLFT} ${INCLUDES}${HDMLX} \
# 			${LIBFT} ${DIRMLX}${MLX} ${MLX}
# 
# re			:	fclean all

.PHONY		:	all bonus clean fclean re