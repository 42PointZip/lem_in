/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:58:11 by lasalced          #+#    #+#             */
/*   Updated: 2015/10/22 14:36:01 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/libft.h"
#include <stdlib.h>

void		ft_expend_neighbor(t_lnode *lnode, int index, int weight)
{
	t_lnode	*tmp;

	tmp = lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->node_link[index] == 1)
			{
				if (tmp->weight > weight)
					tmp->weight = weight;
			}
			tmp = tmp->next;
		}
		if (tmp->node_link[index] == 1)
		{
			if (tmp->weight > weight)
				tmp->weight = weight;
		}
	}
}

int			ft_expend(t_lnode *lnode, int min)
{
	t_lnode	*tmp;
	int		find;

	tmp = lnode;
	find = 0;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->weight == min)
			{
				ft_expend_neighbor(lnode, tmp->index, min + 1);
				find++;
			}
			tmp = tmp->next;
		}
		if (tmp->weight == min)
		{
			ft_expend_neighbor(lnode, tmp->index, min + 1);
			find++;
		}
	}
	return (find);
}

int			ft_little_neighbor(int index_min, t_lnode *lnode, int number_node)
{
	t_lnode	*tmp;
	int		min;
	int		index;

	tmp = lnode;
	min = 2147483647;
	index = -1;
	while (number_node > 0)
	{
		if (tmp->node_link[index_min] == 1)
		{
			if (tmp->weight < min)
			{
				min = tmp->weight;
				index = tmp->index;
			}
		}
		tmp = tmp->next;
		number_node--;
	}
	return (index);
}

char		*ft_calcul_path(t_lnode *lnode, int number_node)
{
	int		index_min;
	int		type;
	char	*path;

	type = 0;
	path = ft_strdup("");
	index_min = ft_give_start(lnode);
	path = ft_strjoin(path, ft_strjoin("\n", ft_name_lnode(index_min, lnode)));
	while (type != 2 && index_min != -1)
	{
		index_min = ft_little_neighbor(index_min, lnode, number_node);
		path = ft_strjoin(path, ft_strjoin("\n", \
			ft_name_lnode(index_min, lnode)));
		type = ft_type_lnode(index_min, lnode);
	}
	if (index_min == -1)
	{
		ft_putendl_fd("ERROR", 2);
		exit(0);
	}
	return (path);
}

char		*ft_dijkstra_setting(t_data data)
{
	int		min;
	int		find;

	min = 0;
	find = 1;
	while (find)
	{
		if (data.lnode->node_link == 0)
		{
			ft_putstr_fd("ERROR\n",2);
			exit(0);
		}
		find = ft_expend(data.lnode, min);
		if (find == 0)
			break ;
		min++;
	}
	return (ft_calcul_path(data.lnode, data.parse->number_node));
}
