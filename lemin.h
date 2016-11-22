/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:37:15 by lasalced          #+#    #+#             */
/*   Updated: 2015/10/22 14:37:11 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct		s_parse
{
	int				ant;
	int				start;
	int				end;
	int				link;
	int				number_node;
}					t_parse;

typedef struct		s_lnode
{
	char			*name;
	int				type;
	int				index;
	int				*node_link;
	int				weight;
	struct s_lnode	*next;
}					t_lnode;

typedef struct		s_data
{
	struct s_lnode	*lnode;
	struct s_parse	*parse;
}					t_data;

void				ft_parse(t_data *data);
void				ft_parse_link(int *step, char *line, t_parse **parse, \
						t_data *data);
void				ft_parse_room(int *step, char *line, t_data *data, \
						t_parse **parse);
void				ft_parse_ant(int *step, char *line, t_parse **parse);
t_lnode				*ft_lnodenew(char *line, int type, int number_node);
void				ft_lnodeadd(t_lnode **lnode, t_lnode *new_node);
void				ft_lnode_add_last(t_lnode **lnode, t_lnode *new_node);
int					ft_lnode_find_elem(t_lnode *lnode, char *elem);
char				*ft_dijkstra_setting(t_data data);
int					ft_give_start(t_lnode *lnode);
int					ft_lnode_check_node(t_lnode *lnode, int index_node, \
						int check_node);
int					ft_lnode_end(t_lnode *lnode);
char				*ft_name_lnode(int index_node, t_lnode *lnode);
int					ft_type_lnode(int index_node, t_lnode *lnode);
void				ft_parse_ant(int *step, char *line, t_parse **parse);
void				ft_add_link(t_data *data, char *first, char *second);
void				ft_parse_link(int *step, char *line, t_parse **parse, \
						t_data *data);
int					ft_lnode_index(t_data *data, char *name_node);

#endif
