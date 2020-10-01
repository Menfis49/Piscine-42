int	ft_test(int a, int b)
{
	return (a - b);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	char a;
	char b;

	i = 1;
	a = 'c';
	b = 'c';
	while (f(tab[i - 1], tab[i]) == 0 && i < length)
	{
		if (i == length - 1)
			return 1;
		i++;
	}
	while (i < length)
	{
		while (f(tab[i - 1], tab[i]) < 0 && i < length)
		{
			a = 'a';
			i++;
		}
		while (f(tab[i - 1], tab[i]) == 0 && i < length)
			i++;
		while (f(tab[i - 1], tab[i]) > 0 && i < length)
		{
			b = 'b';
			i++;
		}
	}
	if ((a == 'a' && b == 'c') || (a == 'c' && b == 'b'))
		return (1);
	else
		return (0);
}

#include <stdio.h>

int	main()
{
	int	tab[5] = {1, 4, 4, 5, -3};
	printf("%d\n", ft_is_sort(tab, 5, &ft_test));
}
