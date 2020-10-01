/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:11:46 by vazra             #+#    #+#             */
/*   Updated: 2020/09/21 11:32:10 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*result;
	long	diff;
	long	i;

	i = 0;
	diff = max - min;
	if (min >= max)
		return (0);
	result = malloc(sizeof(*result) * diff);
	while (i < diff)
	{
		result[i] = min;
		i++;
		min++;
	}
	return (result);
}
