/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:18:36 by bcrespin          #+#    #+#             */
/*   Updated: 2013/12/24 13:50:36 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	char *stemp;

	stemp = (char*)s;
	while (*stemp != '\0' && n > 0)
	{
		if (*stemp == (unsigned char)c)
		{
			return (stemp);
		}
		stemp++;
		n--;
	}
	return (NULL);
}
