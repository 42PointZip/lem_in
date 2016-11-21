/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 14:21:01 by mmole             #+#    #+#             */
/*   Updated: 2015/10/22 14:30:53 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"
#include <stdlib.h>

void		ft_parse_ant(int *step, char *line, t_parse **parse)
{
	if (ft_is_valid_int(line) && ft_atoi(line) > 0)
	{
		*step += 1;
		(*parse)->ant = ft_atoi(line);
	}
	else
		*step = -1;
}

void		ft_add_link(t_data *data, char *first, char *second)
{
	t_lnode	*tmp;
	int		index;

	tmp = data->lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->name, first) == 0)
			{
				index = ft_lnode_index(data, second);
				if (index != -1)
					tmp->node_link[index] = 1;
			}
			tmp = tmp->next;
		}
		if (ft_strcmp(tmp->name, first) == 0)
		{
			index = ft_lnode_index(data, second);
			if (index != -1)
				tmp->node_link[index] = 1;
		}
	}
}

void		ft_parse_link(int *step, char *line, t_parse **parse, t_data *data)
{
	char	**tab;

	tab = ft_strsplit(line, '-');
	if (ft_count_tab(tab) != 2)
	{
		*step = -1;
		return ;
	}
	if (!(ft_lnode_find_elem(data->lnode, tab[0]) \
				&& ft_lnode_find_elem(data->lnode, tab[1])))
		(*parse)->link = -1;
	ft_add_link(data, tab[0], tab[1]);
	ft_add_link(data, tab[1], tab[0]);
	ft_memdel((void **)tab);
}
