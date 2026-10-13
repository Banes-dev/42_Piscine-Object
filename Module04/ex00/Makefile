COMP = c++

CFLAGS = -g -Wall -Wextra -Werror -std=c++20

# Normal
NAME =  School_preparation
FUNC = Course.cpp Room/Room.cpp Room/Classroom.cpp Person/Student.cpp Person/Professor.cpp Person/Staff.cpp Person/Headmaster.cpp Person/Secretary.cpp Form/CourseFinishedForm.cpp Form/NeedMoreClassRoomForm.cpp Form/NeedCourseCreationForm.cpp Form/SubscriptionToCourseForm.cpp
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
