/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlookchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 05:23:30 by mmole             #+#    #+#             */
/*   Updated: 2015/10/11 05:56:56 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlookchar(char *str, char c, int occu)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			occu--;
		if (occu == 0)
			return (i);
		i++;
	}
	return (-1);
}
