/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:14:23 by vazra             #+#    #+#             */
/*   Updated: 2020/09/28 14:48:42 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_exist_base(char *base);
int		contains(char *base, char c);
int		ft_atoi_base(char *str, char *base);

int		size_str_base_to(long nb_atoi, char *base_to)
{
	int i;
	int size_base;

	size_base = ft_strlen(base_to);
	i = 0;
	if (nb_atoi == 0)
		return (2);
	if (nb_atoi < 0)
		nb_atoi = -nb_atoi;
	while (nb_atoi > 0)
	{
		nb_atoi /= size_base;
		i++;
	}
	return (i + 1);
}

char	*convert_nbr_to_base_to(char *result, long nb_atoi, char *base_to)
{
	int size_base;
	int i;

	i = 0;
	size_base = ft_strlen(base_to);
	if (nb_atoi == 0)
		result[0] = base_to[0];
	if (nb_atoi < 0)
	{
		nb_atoi = -nb_atoi;
		result[0] = '-';
		i = size_str_base_to(nb_atoi, base_to);
	}
	else
		i = size_str_base_to(nb_atoi, base_to) - 1;
	result[i] = '\0';
	i--;
	while (nb_atoi > 0)
	{
		result[i] = base_to[nb_atoi % size_base];
		nb_atoi = nb_atoi / size_base;
		i--;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		nb_atoi;

	if (ft_exist_base(base_from) == 0 || ft_exist_base(base_to) == 0)
		return (0);
	nb_atoi = ft_atoi_base(nbr, base_from);
	if (!(res = malloc(sizeof(*res) * size_str_base_to(nb_atoi, base_to))))
		return (0);
	return (convert_nbr_to_base_to(res, nb_atoi, base_to));
}

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		ft_putnbr(INT_MIN / 10);
		ft_putchar(-(INT_MIN % 10) + '0');
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
int		main(void)
{
	char	*nb1 = "\n\t\v\f\r ---+--+1234ab567";
	char	*nb2 = "42";
	char	*nb3 = "01";
	char	*nb4 = "0";
	char	*nb5 = "";
	char	*nb6 = "\t-24a";
	char	*nb7 = "\t-204a";
	char	*nb8 = "\t-a24a";
	char	*nb9 = "33896823";
	char	*base0 = "";
	char	*base1 = "0";
	char	*base2 = "01";
	char	*base10 = "0123456789";
	char	*base10db = "01234567891";
	char	*base10sp = " 123456789";
	char	*base10p = "0123456+789";
	char	*base10m = "0123456-789";
	char	*base10nl = "0123456\n789";
	char	*base16 = "0123456789abcdef";
	char	*basep = "poneyvif";
	char	*nb10 = "-2147483648";
	char	*result = NULL;
	ft_putstr("nb1 = \\n\\t\\v\\f\\r ---+--+1234ab567\nnb2 = 42\nnb3 = 01\nnb4 = 0\nnb5 = \"\"\nnb6 = \\t-24a\nnb7 = \\t-204a\nnb8 = \\t-a24a\nnb9 = 33896823\n");
	ft_putstr("ft_convert_base(nb1, base10, base10), result = ");
	result = ft_convert_base(nb1, base10, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10, base0), result = ");
	result = ft_convert_base(nb1, base10, base0);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base1, base10), result = ");
	result = ft_convert_base(nb1, base1, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(NULL, base10db, base10), result = ");
	result = ft_convert_base(NULL, base10db, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10db, base10), result = ");
	result = ft_convert_base(nb1, base10db, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10sp, base10), result = ");
	result = ft_convert_base(nb1, base10sp, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10p, base10), result = ");
	result = ft_convert_base(nb1, base10p, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10m, base10), result = ");
	result = ft_convert_base(nb1, base10m, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10nl, base10), result = ");
	result = ft_convert_base(nb1, base10nl, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10, base16), result = ");
	result = ft_convert_base(nb1, base10, base16);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb2, base10, base2), result = ");
	result = ft_convert_base(nb2, base10, base2);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb3, base10, base2), result = ");
	result = ft_convert_base(nb3, base10, base2);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb4, base10, base2), result = ");
	result = ft_convert_base(nb4, base10, base2);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb5, base10, basep), result = ");
	result = ft_convert_base(nb5, base10, basep);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb6, base10, base16), result = ");
	result = ft_convert_base(nb6, base10, base16);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb7, base10, base2), result = ");
	result = ft_convert_base(nb7, base10, base2);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb8, base10, base16), result = ");
	result = ft_convert_base(nb8, base10, base16);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb9, base10, basep), result = ");
	result = ft_convert_base(nb9, base10, basep);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb10, base10, base10), result = ");
	result = ft_convert_base(nb10, base10, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	return (0);
}
