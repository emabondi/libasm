NAME = libasm.a
SRCS = ft_strlen.s ft_strcpy.s
OBJS = $(SRCS:.s=.o)

$(NAME):
		nasm -felf64 ft_strlen.s
		nasm -felf64 ft_strcpy.s
		ar rcs $(NAME) $(OBJS)

all: $(NAME) test

test:
	gcc main.c -L. -lasm -o test_main

clean:
		rm $(OBJS)

fclean: clean
		rm test_main $(NAME)

re: fclean all

.PHONY: all test clean fclean re