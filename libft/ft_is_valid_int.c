/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 17:54:12 by lasalced          #+#    #+#             */
/*   Updated: 2015/10/16 18:07:40 by lasalced         ###   ########.fr       */
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
