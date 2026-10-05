COMP = c++

CFLAGS = -g -Wall -Wextra -Werror -std=c++98

# Normal
NAME =  Putting_it_into_practice
FUNC = main.cpp Position.cpp Statistic.cpp Worker.cpp Toll.cpp Shovel.cpp Hammer.cpp WorkShop.cpp
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
