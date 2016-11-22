/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:12:46 by lasalced          #+#    #+#             */
/*   Updated: 2015/01/19 17:12:47 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*mem;
	size_t		i;

	i = 0;
	mem = (char *)malloc(sizeof(char) * size);
	if (mem)
	{
		while (i < size)
		{
			mem[i] = '\0';
			i++;
		}
		return (mem);
	}
	return (NULL);
}
