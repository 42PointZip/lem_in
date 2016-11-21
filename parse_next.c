/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 16:46:10 by mmole             #+#    #+#             */
/*   Updated: 2015/11/05 19:30:38 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"
#include <stdlib.h>

static void	ft_add_first_last_node(int *step, char *line, t_data *data, \
		t_parse **parse)
{
	if (*step == 3)
	{
		if (data->lnode != NULL)
			ft_lnodeadd(&(data->lnode), \
				ft_lnodenew(line, 1, (*parse)->number_node));
		else
			data->lnode = ft_lnodenew(line, 1, (*parse)->number_node);
		(*parse)->start = 1;
		(*parse)->number_node += 1;
		*step += 1;
	}
	else if (*step == 5)
	{
		if (data->lnode != NULL)
			ft_lnodeadd(&(data->lnode), \
				ft_lnodenew(line, 2, (*parse)->number_node));
		else
			data->lnode = ft_lnodenew(line, 2, (*parse)->number_node);
		(*parse)->end = 1;
		(*parse)->number_node += 1;
		*step += 1;
	}
}

static void	ft_parse_check_commande(int *step, char *line, t_data *data, \
		t_parse **parse)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (*step == 1)
		*step += 1;
	else
	{
		if (ft_strcmp(line, "##start") == 0)
			*step = 3;
		else if (ft_strcmp(line, "##end") == 0)
			*step = 5;
		else if (ft_count_tab(tab) == 3 && ft_is_valid_int(tab[1]) \
			&& ft_is_valid_int(tab[2]))
			ft_add_first_last_node(step, line, data, parse);
		else
		{
			*step = -1;
			(*parse)->link = -1;
		}
		if (*step == 4 && (*parse)->end == 1)
			*step = 6;
		if (*step == 6 && (*parse)->start == 0)
			*step = 2;
	}
}

void		ft_prepare_next(t_data *data, int *step, int lenght)
{
	t_lnode	*tmp;

	tmp = data->lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp->node_link = (int *)malloc(sizeof(int) * lenght);
			tmp = tmp->next;
		}
		tmp->node_link = (int *)malloc(sizeof(int) * lenght);
		tmp = tmp->next;
	}
	*step += 1;
}

void		ft_parse_room(int *step, char *line, t_data *data, \
		t_parse **parse)
{
	char	**tab;

	tab = 0;
	if (*step == 1 || *step == 3 || *step == 5 || (line[0] == '#' \
				&& line[1] == '#'))
		ft_parse_check_commande(step, line, data, parse);
	else
	{
		tab = ft_strsplit(line, ' ');
		if (ft_count_tab(tab) == 1)
		{
			if (*step == 6)
				ft_prepare_next(data, step, (*parse)->number_node);
			else
				*step = -1;
		}
		else if (ft_count_tab(tab) != 3 || (ft_count_tab(tab) == 3 \
					&& (ft_is_valid_int(tab[1]) == 0 \
						|| ft_is_valid_int(tab[2]) == 0)))
			*step = -1;
		else
			ft_lnode_add_last(&(data->lnode), \
				ft_lnodenew(line, 3, (*parse)->number_node++));
	}
	ft_memdel((void **)tab);
}

int			ft_lnode_index(t_data *data, char *name_node)
{
	t_lnode	*tmp;

	tmp = data->lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->name, name_node) == 0)
				return (tmp->index);
			tmp = tmp->next;
		}
		if (ft_strcmp(tmp->name, name_node) == 0)
			return (tmp->index);
	}
	return (-1);
}
