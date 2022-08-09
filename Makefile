TARGET = philo

SRC = philo.c protection_tools.c

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