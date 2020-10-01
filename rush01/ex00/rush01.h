/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:18:26 by vazra             #+#    #+#             */
/*   Updated: 2020/09/20 18:33:08 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_print_tab(int **tab, int i, int f);
int		ft_fill(char **av);
void	ft_free(int **tab);
int		ft_solver(char **av, int **tab, int i, int f);
int		ft_check_param(int **tab, char **av);

#endif
