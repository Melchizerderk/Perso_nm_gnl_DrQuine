/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 16:23:36 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:37:23 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void *ft_realloc(void *ptr, size_t size)
{
	void *newptr;

	if (ptr == NULL)
		newptr = (char *)malloc(sizeof(char) * size);
	else
	{
		newptr = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + size + 1));
		ft_memcpy(newptr, ptr, size);
	}
	return (newptr);
}
