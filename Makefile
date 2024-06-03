NAME = mylib.a
SRCS = ft_strlen.s
OBJS = $(SRCS:.s=.o)

$(NAME):
		nasm -felf64 $(SRCS)
		ar rcs libmylib.a $(OBJS)

all: $(NAME) test

test:
	gcc main.c -L. -lmylib -o test_main

clean:
		rm $(OBJS)

fclean: clean
		rm test_main libmylib.a

re: fclean all

.PHONY: all test clean fclean re