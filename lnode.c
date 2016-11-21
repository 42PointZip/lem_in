/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnode.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 18:41:50 by mmole             #+#    #+#             */
/*   Updated: 2015/10/22 16:55:53 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"
#include <stdlib.h>

t_lnode		*ft_lnodenew(char *line, int type, int number_node)
{
	t_lnode	*new_node;
	char	*strim_string;

	new_node = (t_lnode *)malloc(sizeof(t_lnode));
	strim_string = ft_strtrim(line);
	new_node->name = ft_strsub(strim_string, 0, \
		ft_strlookchar(strim_string, ' ', 1));
	new_node->type = type;
	new_node->index = number_node;
	new_node->node_link = NULL;
	if (type != 2)
		new_node->weight = 2147483647;
	else
		new_node->weight = 0;
	return (new_node);
}

void		ft_lnodeadd(t_lnode **lnode, t_lnode *new_node)
{
	if (lnode != NULL && new_node)
	{
		new_node->next = *lnode;
		*lnode = new_node;
	}
}

void		ft_lnode_add_last(t_lnode **lnode, t_lnode *new_node)
{
	t_lnode	*tmp;

	tmp = *lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	else
		*lnode = new_node;
}

int			ft_lnode_find_elem(t_lnode *lnode, char *elem)
{
	t_lnode	*tmp;

	tmp = lnode;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->name, elem) == 0)
			return (1);
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->name, elem) == 0)
		return (1);
	return (0);
}
