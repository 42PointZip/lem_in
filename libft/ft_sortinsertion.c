/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortinsertion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:12:46 by lasalced          #+#    #+#             */
/*   Updated: 2015/01/22 15:42:57 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortinsertion(int **tab, size_t n)
{
	int		tmp;
	size_t	i;
	size_t	j;

	i = 1;
	while (i < n)
	{
		tmp = (*tab)[i];
		j = i;
		while (j > 0 && (*tab)[j - 1] > tmp)
		{
			(*tab)[j] = (*tab)[j - 1];
			j = j - 1;
		}
		(*tab)[j] = tmp;
		i++;
	}
}
