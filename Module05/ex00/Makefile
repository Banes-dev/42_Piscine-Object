COMP = c++

CFLAGS = -g -Wall -Wextra -Werror -std=c++20

# Normal
NAME =  Train_yourself
FUNC = main.cpp Network/Node.cpp Network/Rail.cpp Network/Network.cpp Network/NetworkFactory.cpp
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
