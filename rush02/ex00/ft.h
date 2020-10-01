/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:06:29 by jacher            #+#    #+#             */
/*   Updated: 2020/09/27 21:20:47 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct		s_dico
{
	char			*chiffre;
	char			*lettre;
}					t_dico;

typedef struct		s_list
{
	char			*aff;
	struct s_list	*next;
}					t_result;

int					ft_strlen(char *str);
int					check_num(char *av);
int					check_argv(int ac, char **av);
int					work_dico_av(char *av, int *lines);
int					dico_to_str_av(char *dico, char *av);
int					split_str_to_tab(char *str, char car, char	**tab);
void				print_tabtab(char **tab);
int					check_dico(char **dico_tab);
void				print_struct(t_dico *tab);
t_dico				*split_dico(char **dico_tab, int lines);
int					cmp(t_dico *tab, char *av, t_result **b_list, int nb);
int					ft_strcmp(char *s1, char *s2);
int					check_base_dico(t_dico *dico_tab);
t_result			*ft_create_elem(char *data);
void				ft_list_push_back(t_result **b_list, char *data);
void				print_result(t_result **b_list);
char				*ft_strdup(char *data);
void				free_dico_tab(char **dico_tab);
void				free_dico_struct(t_dico *dico_struct);
void				free_list_result(t_result **b_list);
int					nb_void(int nb, char *av, t_dico *tab, t_result **b_list);
int					nb_cent(int nb, char *av, t_dico *tab, t_result **b_list);
int					nb_diz(int nb, char *av, t_dico *tab, t_result **b_list);
int					nb_units(int nb, char *av, t_dico *tab, t_result **b_list);
void				ft_get_temp(char temp[3], char *av, int nb);
int					num_temp_zero(t_dico *tab, t_result **b_list);
int					look_for_sep(int nb, t_dico *tab, t_result **b_list);
int					look_doubles(char *temp, t_dico *tab, t_result **b_list);
void				ft_putstr(char *str);
void				cmp_main(t_dico *dico_struct, char **av, t_result *b_list);
char				*put_dico_main(int ac, char **av);
int					main2(int lines, int count, char *source, char **av);
int					main3(int lines, char **av, char **dico_tab);
void				error(int i);
#endif
