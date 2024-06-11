NAME = libasm.a
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s
OBJS = $(SRCS:.s=.o)

%.o: %.s
	nasm -f elf64 -o $@ $<

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all: $(NAME) test

test:
	gcc main.c -L. -lasm -o test_main

clean:
		rm $(OBJS)

fclean: clean
		rm test_main $(NAME)
		rm test_ft_read.txt

re: fclean all

.PHONY: all test clean fclean re