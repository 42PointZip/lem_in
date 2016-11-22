/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
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

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (s && *s)
	{
		while (s[i] && i < (len + start))
		{
			str[i - start] = s[i];
			i++;
		}
		str[i - start] = '\0';
		return (str);
	}
	return (NULL);
}
