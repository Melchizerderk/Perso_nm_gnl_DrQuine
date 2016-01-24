/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schain_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 19:17:58 by bcrespin          #+#    #+#             */
/*   Updated: 2014/10/07 17:32:48 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "lib_struct.h"
#include "libft.h"

t_list		*create_elem(void *data)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

t_list		*putback_elem(t_list *new_list, void *data)
{
	t_list	*temp;

	if (new_list == NULL)
		return (create_elem(data));
	else
	{
		temp = new_list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = create_elem(data);
		return (new_list);
	}
}

t_list		*putfront_elem(t_list *new_list, void *data)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	new_elem->data = data;
	new_elem->next = new_list;
	return (new_elem);
}
