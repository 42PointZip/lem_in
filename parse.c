/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 15:35:30 by lasalced          #+#    #+#             */
/*   Updated: 2015/11/05 23:32:31 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lemin.h"
#include <stdlib.h>

static t_parse	*ft_init_parse(void)
{
	t_parse	*parse;

	parse = (t_parse *)malloc(sizeof(t_parse));
	parse->ant = -1;
	parse->start = -1;
	parse->end = -1;
	parse->link = 1;
	parse->number_node = 0;
	return (parse);
}

static void		ft_check_valid(t_data *data, char *text, t_parse *parse_struct)
{
	int		error;
	char	*str;

	error = 0;
	str = ft_strdup("ERROR\nYou need write ");
	data->parse = parse_struct;
	if (data->parse->ant == -1 || data->parse->start == -1 || data->parse->end \
		== -1 || data->parse->link == -1)
		error = 1;
	if (data->parse->ant == -1)
		str = ft_strjoin(str, "Integer number of ant on first ligne\n");
	else if (data->parse->start == -1)
		str = ft_strjoin(str, "##start and valide name, coord after ligne\n");
	else if (data->parse->end == -1)
		str = ft_strjoin(str, "##end and valide name, coord after ligne\n");
	else if (data->parse->link == -1)
		str = ft_strjoin(str, "An correct define link\n");
	if (error)
	{
		ft_putstr_fd(str, 2);
		free(str);
		ft_memdel((void **)data);
		exit(0);
	}
	ft_putstr(text);
}

int				ft_continue(char *line)
{
	if ((ft_strlen(line) == 1 && line[0] == '#') \
	|| (ft_strlen(line) >= 2 && line[0] == '#' && line[1] != '#') \
	|| ((ft_strlen(line) >= 2 && line[0] == '#' && line[1] == '#') \
	&& (!(ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0))))
		return (1);
	return (0);
}

void			ft_parse(t_data *data)
{
	char		*line;
	int			step;
	char		*text;
	t_parse		*parse_struct;

	step = 0;
	text = NULL;
	parse_struct = ft_init_parse();
	while (step >= 0 && get_next_line(0, &line))
	{
		line = ft_strtrim(line);
		if (ft_strlen(ft_strtrim(line)) == 0)
			step = -1;
		if (ft_continue(line))
			continue ;
		if (step == 0)
			ft_parse_ant(&step, line, &parse_struct);
		if (step >= 1 && step <= 6)
			ft_parse_room(&step, line, data, &parse_struct);
		if (step == 7)
			ft_parse_link(&step, line, &parse_struct, data);
		text = ft_strjoin(text, ft_strjoin(line, "\n"));
	}
	ft_check_valid(data, text, parse_struct);
}
