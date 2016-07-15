/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ladd_rear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:33:18 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:27:16 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ladd_rear(t_list *lst, void *value)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = lnew(value);
	return (lst);
}
