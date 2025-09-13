CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
NAME = interface
SRCS = main.cpp MateriaSource.cpp Ice.cpp Cure.cpp Character.cpp AMateria.cpp
OBJS = $(SRCS:.cpp=.o)
${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}
all: ${NAME}
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all
.PHONY: all clean fclean re