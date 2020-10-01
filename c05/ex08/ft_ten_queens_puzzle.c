/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:58:53 by vazra             #+#    #+#             */
/*   Updated: 2020/09/17 15:12:10 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_board(int *board)
{
	int column;
	char c;

	column = 0;
	while (column < 10)
	{
		c = board[column] + 48;
		write(1, &c, 1);
		column++;
	}
	write(1, "\n", 1);
}

int	ft_absolute(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

int	ft_check_other_queens(int *board, int index)
{
	int	free;
	int	o_index;

	free = 1;
	o_index = -1;
	while ((++o_index < index) && (free == 1))
	{
		if (board[index] == board[o_index])
			free = 0;
		if (ft_absolute(o_index - index) == ft_absolute(board[o_index] - board[index]))
			free = 0;
	}
	return (free);
}

void	ft_put_queen(int index, int *count)
{
	static int board[10] = {0};
	int pos;

	pos = 0;
	while (pos < 10)
	{
		board[index] = pos;
		if (ft_check_other_queens(board, index))
		{
			if (index < 9)
				ft_put_queen(index + 1, count);
			else
			{
				++(*count);
				ft_put_board(board);
			}
		}
		pos++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int possibilities;

	possibilities = 0;
	ft_put_queen(0, &possibilities);
	return (possibilities);
}


int	main()
{
//	int board[10]={0};
//	ft_put_board(board);
//	printf("%d", ft_check_other_queens(board, 0));
//	int a = 0;
//	a = ft_ten_queens_puzzle();
	ft_ten_queens_puzzle();
//	printf("%d", a);
}
