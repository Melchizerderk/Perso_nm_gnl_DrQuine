/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dchain_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/30 12:07:46 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/11 19:26:44 by bcrespin         ###   ########.fr       */
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

t_list	*putafterbefore_elemd(t_list *list, void *data, int i)
{
	t_list *temp;
	
	if (i == 1)
	{
		if (list->next == NULL)
			list->next = create_elemd(list, data);
		else
		{
			temp = list->next;
			list->next = create_elemd(list, data);
			temp->prev = list->next;
			list = list->next;
			list->next = temp;
		}
	}
	else if (i == -1)
	{
		if (list->prev == NULL)
			list->prev = putfront_elemd(list, data);
		else
		{
			temp = list->prev;
			list->prev = create_elemd(temp, data);
			temp->next = list->prev;
			temp = temp->next;
			temp->prev = temp;
		}
	}
	return (list);
}
