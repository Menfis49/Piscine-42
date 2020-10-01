/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_base_dico.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:41:32 by jacher            #+#    #+#             */
/*   Updated: 2020/09/29 15:58:20 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		check_dico(char **dico_tab)
{
	int i;
	int j;

	i = 0;
	while (dico_tab[i] != 0)
	{
		j = 0;
		while (dico_tab[i][j] != '\0')
		{
			while (dico_tab[i][j] >= '0' && dico_tab[i][j] <= '9')
				j++;
			while (dico_tab[i][j] == ' ')
				j++;
			if (dico_tab[i][j] != ':')
				return (-1);
			j++;
			while (dico_tab[i][j] >= 32 && dico_tab[i][j] <= 126)
				j++;
			if (dico_tab[i][j] != '\0')
				return (-1);
		}
		i++;
	}
	return (1);
}

void	allocate_one_to_nineteen(char *tab[41])
{
	tab[0] = "0";
	tab[1] = "1";
	tab[2] = "2";
	tab[3] = "3";
	tab[4] = "4";
	tab[5] = "5";
	tab[6] = "6";
	tab[7] = "7";
	tab[8] = "8";
	tab[9] = "9";
	tab[10] = "10";
	tab[11] = "11";
	tab[12] = "12";
	tab[13] = "13";
	tab[14] = "14";
	tab[15] = "15";
	tab[16] = "16";
	tab[17] = "17";
	tab[18] = "18";
	tab[19] = "19";
}

void	allocate_over_twenty(char *tab[41])
{
	tab[20] = "20";
	tab[21] = "30";
	tab[22] = "40";
	tab[23] = "50";
	tab[24] = "60";
	tab[25] = "70";
	tab[26] = "80";
	tab[27] = "90";
	tab[28] = "100";
	tab[29] = "1000";
	tab[30] = "1000000";
	tab[31] = "1000000000";
	tab[32] = "1000000000000";
	tab[33] = "1000000000000000";
	tab[34] = "1000000000000000000";
	tab[35] = "1000000000000000000000";
	tab[36] = "1000000000000000000000000";
	tab[37] = "1000000000000000000000000000";
	tab[38] = "1000000000000000000000000000000";
	tab[39] = "1000000000000000000000000000000000";
	tab[40] = "1000000000000000000000000000000000000";
}

int		check_base_dico(t_dico *dico_struct)
{
	char	*tab[41];
	int		i;
	int		j;

	allocate_one_to_nineteen(tab);
	allocate_over_twenty(tab);
	i = 0;
	while (i < 41)
	{
		j = 0;
		while (dico_struct[j].chiffre != 0)
		{
			if (ft_strcmp(dico_struct[j].chiffre, tab[i]) == 0)
				break ;
			j++;
		}
		if (dico_struct[j].chiffre == 0)
			return (-1);
		i++;
	}
	return (1);
}
