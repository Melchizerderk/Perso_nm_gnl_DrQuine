/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:10:51 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/31 17:14:02 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_listnmo	*ft_sort_swap(int *d, t_listnmo *tmp, char *strtbl, struct nlist_64 *array)
{
	int			tdata;
	t_listnmo	*tmp2;

	while (tmp->next != NULL)
	{
		if (ft_strcmp(strtbl + array[tmp->data].n_un.n_strx, \
					strtbl + array[tmp->next->data].n_un.n_strx) > 0)
		{
			*d = 0;
			tdata = tmp->data;
			tmp->data = tmp->next->data;
			tmp->next->data = tdata;
		}
		else if (ft_strequ(strtbl + array[tmp->data].n_un.n_strx, \
					strtbl + array[tmp->next->data].n_un.n_strx))
		{
			tmp2 = tmp->next;
			if (tmp2->next == NULL)
			{
				free(tmp2->next);
				tmp->next = NULL;
			}
			else
			{
				tmp2 = tmp2->next;
				free(tmp2->prev);
				tmp->next = tmp2;
				tmp2->prev = tmp;
			}
		}
		tmp = tmp->next;
	}
	return (tmp);
}

t_listnmo	*ft_sort(int nsyms, char *strtbl, struct nlist_64 *array, t_listnmo *lst_sym)
{
	int			i;
	int			d;
	t_listnmo	*tmp;

	d = 0;
	i = 0;
	while (i < nsyms)
	{
		if ((ft_strnequ(strtbl + array[i].n_un.n_strx, "_", 1)
				|| ft_strequ(strtbl + array[i].n_un.n_strx, DYSB)))
			lst_sym = put_elem_back(lst_sym, i);
		i++;
	}
	while (d == 0)
	{
		tmp = lst_sym;
		d = 1;
		tmp = ft_sort_swap(&d, tmp, strtbl, array);
	}
	return (lst_sym);
}
