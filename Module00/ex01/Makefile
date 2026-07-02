COMP = c++

CFLAGS = -g -Wall -Wextra -Werror -std=c++98

# Normal
NAME =  I_dont_know_what_im_doing_!
FUNC = main.cpp
OBJS = $(FUNC:.cpp=.o)


# Compil
all: 	${NAME}

${NAME}: ${OBJS}
	${COMP} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	${COMP} ${CFLAGS} -c $< -o $@

clean:	
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
