/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 21:11:16 by lasalced          #+#    #+#             */
/*   Updated: 2015/10/22 20:41:08 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"
#include <stdlib.h>

void		ft_print_path(char **tab, int **tabant, int number_ant)
{
	int		i;
	int		print;

	i = 0;
	print = 0;
	while (i < number_ant)
	{
		if (tabant[i][0] != -1)
		{
			if (print > 0)
				ft_putchar(' ');
			ft_putchar('L');
			ft_putnbr(i + 1);
			ft_putchar('-');
			ft_putstr(tab[tabant[i][1]]);
			tabant[i][1] += 1;
			if (tab[tabant[i][1]] == NULL)
				tabant[i][0] = -1;
			print += 1;
		}
		i++;
	}
	if (print > 0)
		ft_putchar('\n');
}

void		ft_print_result(t_data data, char *path)
{
	int		i;
	char	**tab;
	int		**tabant;

	i = 0;
	tabant = (int **)malloc(sizeof(int *) * data.parse->ant);
	tab = ft_strsplit(path, '\n');
	ft_putchar('\n');
	while (i < data.parse->ant)
	{
		tabant[i] = (int *)malloc(sizeof(int) * 2);
		tabant[i][0] = -1;
		tabant[i][1] = 1;
		i++;
	}
	i = 0;
	while (i < data.parse->ant + ft_count_tab(tab))
	{
		if (i < data.parse->ant)
			tabant[i][0] = 1;
		ft_print_path(tab, tabant, data.parse->ant);
		i++;
	}
}

int			main(void)
{
	t_data	data;
	t_lnode	*tmp;
	char	*path;

	ft_parse(&data);
	tmp = data.lnode;
	path = ft_dijkstra_setting(data);
	ft_print_result(data, path);
	return (0);
}
