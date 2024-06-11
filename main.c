#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

extern size_t	ft_strlen(const char *str);
extern char		*ft_strcpy(char *dest, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char 	*ft_strdup(const char *s);

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
		//int p[2]; pipe(p);
		//close(p[0]);
		//printf("closedddddd ft_write(%d, \"%s\", 15): ", p[0], str[i]);
		//ssize_t ret1 = ft_write(p[0], str[i], 15);
		//int s_errno = errno;
		//printf("return: %zd, errno: %d\n", ret1, s_errno);
//
		//errno = 0;
//
		//// Using write
		//printf("write(%d, \"%s\", 15):    ", p[0], str[i]);
		//ssize_t ret2 = write(p[0], str[i], 15);
		//printf("return: %zd, errno: %d\n", ret2, errno);
//
		//// Check return values
		//if (ret1 == ret2 && s_errno == errno)
		//	printf("\033[0;32m RETURN VALUE OK \033[0m\n");
		//else
		//	printf("\033[0;31m RETURN VALUE KO \033[0m\n");
		//
		//close(p[1]);
		//
//
		for (int j = -1; j < 4; j++) {
			int saved_errno;

			// Using ft_write
			printf("ft_write(%d, \"%s\", 15): ", j, str[i]);
			ssize_t ret1 = ft_write(j, str[i], 15);
			saved_errno = errno;
			printf("return: %zd, errno: %d\n", ret1, saved_errno);

			// Reset errno for the next call
			errno = 0;

			// Using write
			printf("write(%d, \"%s\", 15):    ", j, str[i]);
			ssize_t ret2 = write(j, str[i], 15);
			printf("return: %zd, errno: %d\n", ret2, errno);

			// Check return values
			if (ret1 == ret2 && saved_errno == errno)
				printf("\033[0;32m RETURN VALUE OK \033[0m\n");
			else
				printf("\033[0;31m RETURN VALUE KO \033[0m\n");
		}
	}

	printf("\n\033[0;33m CHECKING FT_READ\033[0m\n");
	FILE *fptr;
	fptr = fopen("test_ft_read.txt", "w");
	fprintf(fptr, "Testo per il file di prova");
	fclose(fptr);
	int f = open("test_ft_read.txt", O_RDONLY);
	char reader[30];
	for (int j = -1; j <= f + 2; j++) {
		if (j == 0 || j == 1 || j == 2 || j == f)
			continue;
		int saved_errno;

		// Using ft_read
		int fd = open("test_ft_read.txt", O_RDONLY);
		printf("ft_read(%d, reader, 15): ", j);
		ssize_t ret1 = ft_read(j, reader, 15);
		saved_errno = errno;
		printf("return: %zd, errno: %d\n", ret1, saved_errno);
		if (ret1 > 0)
			printf("buffer: %s\n", reader);
		close(fd);

		// Reset errno for the next call
		errno = 0;

		// Using read
		fd = open("test_ft_read.txt", O_RDONLY);
		printf("read(%d, reader, 15):    ", j);
		ssize_t ret2 = read(j, reader, 15);
		printf("return: %zd, errno: %d\n", ret2, errno);
		if (ret1 > 0)
			printf("buffer: %s\n", reader);
		close(fd);

		// Check return values
		if (ret1 == ret2 && saved_errno == errno)
			printf("\033[0;32m RETURN VALUE OK \033[0m\n");
		else
			printf("\033[0;31m RETURN VALUE KO \033[0m\n");
	}
	close(f);

	printf("\n\033[0;33m CHECKING FT_STRDUP\033[0m\n");
	printf("Word               strdup     strcmp\n");
	char *dup;
	for (int i = 0; str[i] != NULL; i++) {
		dup =	ft_strdup(str[i]);
		printf("%13.13s  %13.13s   ", str[i], dup);
		if (!strcmp(str[i], dup))
			printf ("\033[0;32m OK \033[0m\n");
		else
			printf ("\033[0;31m KO \033[0m\n");
		free(dup);
	}
}