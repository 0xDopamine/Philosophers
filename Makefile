TARGET = philo

SRC = philo.c msgs_and_colors.c supervision.c protection_tools.c simulation.c time_tools.c routine.c

OBJS = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

DEL = rm -f

all: $(TARGET)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	cc $(FLAGS) -lpthread $(OBJS) -o $(TARGET)

re: fclean all

clean:
	$(DEL) $(OBJS)

fclean:	clean
	$(DEL) $(TARGET)

.PHONY: clean fclean re all