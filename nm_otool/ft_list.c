/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:23:09 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/30 16:38:17 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_listnmo *create_first_element(int data)
{
	t_listnmo *new_elem;

	new_elem = malloc(sizeof(t_listnmo));
	new_elem->data = data;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

t_listnmo *create_element(t_listnmo *temp, int data)
{
	t_listnmo	*new_elem;

	new_elem = create_first_element(data);
	new_elem->prev = temp;
	return (new_elem);
}

t_listnmo *put_elem_back(t_listnmo *new_list, int data)
{
	t_listnmo *temp;

	if (new_list == NULL)
		return (create_first_element(data));
	else
	{
		temp = new_list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = create_element(temp, data);
		return (new_list);
	}
}

t_listnmo *put_elem_front(t_listnmo *new_list, int data)
{
	t_listnmo *new_elem;

	new_elem = malloc(sizeof(t_listnmo));
	new_elem->data = data;
	new_elem->next = new_list;
	new_elem->prev = NULL;
	return (new_elem);
}
