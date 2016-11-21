/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <mmole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 17:54:12 by mmole             #+#    #+#             */
/*   Updated: 2015/10/16 18:07:40 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_is_valid_int(const char *str)
{
	if (str && *str)
	{
		if (*str == '-' || *str == '+')
			str++;
		if (*str == '\0')
			return (0);
		while (*str)
		{
			if (ft_isdigit(*str))
				str++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
