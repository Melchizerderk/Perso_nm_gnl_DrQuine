/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:10:51 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/24 17:21:38 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_list	*ft_sort_swap(int *d, t_list *tmp, char *strtbl, struct nlist_64 *array)
{
	char *tdata;

	tdata = NULL;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(strtbl + array[ft_atoi(tmp->data)].n_un.n_strx, \
					strtbl + array[ft_atoi(tmp->next->data)].n_un.n_strx) > 0)
		{
			*d = 0;
			tdata = ft_strdup(tmp->data);
			tmp->data = ft_strcpy(tmp->data, tmp->next->data);
			tmp->next->data = ft_strcpy(tmp->next->data, tdata);
			free(tdata);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

t_list	*ft_sort(int nsyms, char *strtbl, struct nlist_64 *array, t_list *lst_sym)
{
	int		i;
	int		d;
	t_list	*tmp;

	d = 0;
	i = 0;
	while (i < nsyms)
	{
		lst_sym = putback_elemd(lst_sym, ft_itoa(i));
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
