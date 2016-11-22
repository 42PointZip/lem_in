/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnode_methode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 14:08:07 by lasalced          #+#    #+#             */
/*   Updated: 2015/10/22 14:16:15 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

int			ft_lnode_check_node(t_lnode *lnode, int index_node, int check_node)
{
	t_lnode	*tmp;

	tmp = lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->index == index_node)
				return (tmp->node_link[check_node]);
			tmp = tmp->next;
		}
		if (tmp->index == index_node)
			return (tmp->node_link[check_node]);
	}
	return (-1);
}

int			ft_lnode_end(t_lnode *lnode)
{
	t_lnode	*tmp;

	tmp = lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->type == 2)
				return (tmp->index);
			tmp = tmp->next;
		}
		if (tmp->type == 2)
			return (tmp->index);
	}
	return (-1);
}

int			ft_give_start(t_lnode *lnode)
{
	t_lnode	*tmp;

	tmp = lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->type == 1)
				return (tmp->index);
			tmp = tmp->next;
		}
		if (tmp->type == 1)
			return (tmp->index);
	}
	return (-1);
}

char		*ft_name_lnode(int index_node, t_lnode *lnode)
{
	t_lnode	*tmp;

	tmp = lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->index == index_node)
				return (tmp->name);
			tmp = tmp->next;
		}
		if (tmp->index == index_node)
			return (tmp->name);
	}
	return (NULL);
}

int			ft_type_lnode(int index_node, t_lnode *lnode)
{
	t_lnode	*tmp;

	tmp = lnode;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->index == index_node)
				return (tmp->type);
			tmp = tmp->next;
		}
		if (tmp->index == index_node)
			return (tmp->type);
	}
	return (-1);
}
