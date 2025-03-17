#include "../libs/galloc/includes/galloc.h"

int main(void)
{
	init_galloc();
	char *str = "hello world";
	char *str2 = galloc(120 * sizeof(char));
	for(int i = 0; i < ft_strlen(str); i++)
		str2[i] = str[i];
	char *str3 = galloc(120 * sizeof(char));
	for(int i = 0; i < ft_strlen(str); i++)
		str3[i] = str[i];
	char *str4 = galloc(120 * sizeof(char));
	for(int i = 0; i < ft_strlen(str); i++)
		str4[i] = str[i];
	char *str5 = malloc(120 * sizeof(char));
	add_galloc(str5);
	for(int i = 0; i < ft_strlen(str); i++)
		str5[i] = str[i];
	gfree(str5);
	printf("str: %s\n", str2);
	gfree(str4);
	gfree(str2);
	printf("str: %s\n", str3);
	//printf("str: %s\n", str);
	//printf("str: %s\n", str5);
	terminate(42);
}
