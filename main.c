#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern size_t	ft_strlen(const char *str);
extern char*	ft_strcpy(char *dest, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t count);

int main(){
	const char* str[] = {"Prova prova", "Prova2", "", " ", "\0", "precipitevolissimevolmente", "ggggggmeoli", NULL};
	size_t res1, res2;
	printf("\n\033[0;33m CHECKING FT_STRLEN\033[0m\n");
	printf("Word           res_ft_strlen  res_strlen\n");
	for (int i = 0; str[i] != NULL; i++) {
		res1 = ft_strlen(str[i]);
		res2 = strlen(str[i]);
		printf("%13.13s   %8.lu  %10.lu     ", str[i], res1, res2);
		if (res1 == res2)
			printf ("\033[0;32m OK \033[0m\n");
		else
			printf ("\033[0;31m KO \033[0m\n");

	}

	printf("\n\033[0;33m CHECKING FT_STRCPY\033[0m\n");
	printf("Word           res_ft_strcpy  strcmp_check\n");
	char *dest;
	dest = malloc(sizeof(char) * 50);
	char *ret;
	for (int i = 0; str[i] != NULL; i++) {
		ret = ft_strcpy(dest, str[i]);
		//printf("qui%s %squi\n",ret, dest);
		printf("%13.13s   %13.13s      ", str[i], dest);

		if (strcmp(str[i], ret) == 0 && strcmp(str[i], dest) == 0)
			printf ("\033[0;32m OK \033[0m\n");
		else
			printf ("\033[0;31m KO \033[0m\n");
	}

	printf("\n\033[0;33m CHECKING FT_STRCMP\033[0m\n");
	char *test = "Prova2";
	printf("Word used to test: %s\n", test);
	printf("Word           res_ft_strcmp  res_strcmp\n");
	int ret1, ret2;
	for (int i = 0; str[i] != NULL; i++) {
		ret1 = ft_strcmp(str[i], test);
		ret2 = strcmp(str[i], test);
		printf("%13.13s   %8.d  %10.d     ", str[i], ret1, ret2);
		if (res1 == res2)
			printf ("\033[0;32m OK \033[0m\n");
		else
			printf ("\033[0;31m KO \033[0m\n");
	}

	printf("\n\033[0;33m CHECKING FT_WRITE\033[0m\n");
	for (int i = 0; str[i] != NULL; i++) {
		for (int j = -1; j < 4; j++){
			write(j, "ft_write:", 9);
			ret1 = ft_write(j, str[i], 15);
			write(j,"     write:", 11);
			ret2 = write(j, str[i], 15);

			if (res1 == res2)
				printf ("\033[0;32m RETURN VALUE OK \033[0m\n");
			else
				printf ("\033[0;31m RETURN VALUE KO \033[0m\n");
		}
	}
}