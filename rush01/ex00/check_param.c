/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:18:55 by vazra             #+#    #+#             */
/*   Updated: 2020/09/20 18:08:07 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_rev_col(int i, int column, int **tab)
{
	int j;
	int count;

	count = 0;
	j = 0;
	while (i >= 0)
	{
		if (tab[column][i] == 0)
			return (0);
		if (j < tab[i][column])
		{
			j = tab[i][column];
			count++;
		}
		i--;
	}
	return (count);
}

int	ft_check_col(int **tab, char **av, int column, int num_av)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < 4)
	{
		if (tab[column][i] == 0)
			return (0);
		if (j < tab[i][column])
		{
			j = tab[i][column];
			count++;
		}
		i++;
	}
	if ((av[1][num_av] - '0') != count)
		return (0);
	i = i - 1;
	count = ft_check_rev_col(i, column, tab);
	if ((av[1][num_av + 8] - '0') != count)
		return (0);
	return (1);
}

int	ft_check_rev_row(int i, int lign, int **tab)
{
	int j;
	int count;

	count = 0;
	j = 0;
	while (i >= 0)
	{
		if (tab[lign][i] == 0)
			return (0);
		if (j < tab[lign][i])
		{
			j = tab[lign][i];
			count++;
		}
		i--;
	}
	return (count);
}

int	ft_check_row(int **tab, char **av, int lign, int num_av)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < 4)
	{
		if (tab[lign][i] == 0)
			return (0);
		if (j < tab[lign][i])
		{
			j = tab[lign][i];
			count++;
		}
		i++;
	}
	if ((av[1][num_av] - '0') != count)
		return (0);
	i--;
	count = ft_check_rev_row(i, lign, tab);
	if ((av[1][num_av + 8] - '0') != count)
		return (0);
	return (1);
}

int	ft_check_param(int **tab, char **av)
{
	int f;
	int num_av;

	f = 0;
	num_av = 0;
	while (f < 4)
	{
		if (ft_check_col(tab, av, f, num_av) != 1)
			return (0);
		num_av = num_av + 2;
		f++;
	}
	f = 0;
	num_av = 16;
	while (f < 4)
	{
		if (ft_check_row(tab, av, f, num_av) != 1)
			return (0);
		num_av = num_av + 2;
		f++;
	}
	return (1);
}
