/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ladd_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:31:00 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:27:44 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ladd_front(t_list *lst, void *value)
{
	t_list	*tmp;

	tmp = lnew(value);
	tmp->next = lst;
	return (tmp);
}
