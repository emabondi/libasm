#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *str);

int main(){
	const char* str[] = {"Prova prova", "Prova2", "", " ", "\0", "precipitevolissimevolmente", "ggggggmeoli", NULL};
	size_t res1, res2;
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
}