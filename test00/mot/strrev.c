char	*strrev(char *str)
{
	int i;
	int j;
	char temp;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (j <= i)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		j++;
		i--;
	}
	return str;
}

#include <stdio.h>

int	main(int ac, char **av)
{
	char coco[] = "Salut";
	strrev(coco);
	printf("%s\n", coco);
}
