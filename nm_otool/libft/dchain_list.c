/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dchain_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/30 12:07:46 by bcrespin          #+#    #+#             */
/*   Updated: 2014/10/25 18:05:21 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_struct.h"

t_list	*create_first_elemd(void *data)
{
	t_list *new_elem;

	new_elem = malloc(sizeof(t_list));
	new_elem->data = data;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	new_elem->head = 1;
	return (new_elem);
}

t_list	*create_elemd(t_list *temp, void *data)
{
	t_list	*new_elem;

	new_elem = create_first_elemd(data);
	new_elem->prev = temp;
	new_elem->head = 0;
	return (new_elem);
}

t_list	*putback_elemd(t_list *new_list, void *data)
{
	t_list	*temp;

	if (new_list == NULL)
		return (create_first_elemd(data));
	else
	{
		temp = new_list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = create_elemd(temp, data);
		return (new_list);
	}
}

t_list	*putfront_elemd(t_list *new_list, void *data)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	new_elem->data = data;
	new_elem->next = new_list;
	new_elem->prev = NULL;
	return (new_elem);
}
