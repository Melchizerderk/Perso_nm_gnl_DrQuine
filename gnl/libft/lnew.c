/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnew.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 15:07:41 by bcrespin          #+#    #+#             */
/*   Updated: 2014/01/27 19:44:20 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*lnew(void *value)
{
	t_list	*tmp;

	if ((tmp = malloc(sizeof(t_list))))
	{
		tmp->data = value;
		tmp->next = NULL;
	}
	return (tmp);
}
