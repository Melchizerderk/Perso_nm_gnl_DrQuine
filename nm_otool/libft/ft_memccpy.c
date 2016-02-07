/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:57:59 by bcrespin          #+#    #+#             */
/*   Updated: 2013/12/24 14:15:26 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void *ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s2 == (unsigned char)c)
		{
			s1++;
			return (s1);
		}
		else
		{
			*(unsigned char *)s1 = *(unsigned char *)s2;
			n--;
			s1++;
			s2++;
		}
	}
	return (NULL);
}
