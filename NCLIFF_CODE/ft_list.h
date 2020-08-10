/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 02:40:53 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/08/09 21:26:27 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct			s_list
{
	long int			n_ten;
	void				*value;
	void				*key;
	struct s_list		*next;
}						t_list;
t_list					*ft_create_elem(void *value, void *key);
t_list					*ft_list_at(t_list *begin_list, unsigned int nbr);
void					ft_list_clear(t_list *begin_list,
		void (*free_fct)(void *));
t_list					*ft_list_find(t_list *begin_list,
		void *data_ref, int (*cmp)());
void					ft_list_foreach(t_list *begin_list, void (*f)(void *));
void					ft_list_foreach_if(t_list *hd, void (*f)(void *),
		void *dr, int (*c)());
t_list					*ft_list_last(t_list *begin_list);
void					ft_list_push_back(t_list **begin_list, t_list *add_node);
void					ft_list_push_front(t_list **begin_list, void *value, void *key);
int						ft_list_size(t_list *begin_list);
t_list					*ft_list_push_strs(char **strs);

#endif
