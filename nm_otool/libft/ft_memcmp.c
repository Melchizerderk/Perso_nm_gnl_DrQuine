/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:40:50 by bcrespin          #+#    #+#             */
/*   Updated: 2013/12/24 14:18:44 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (*(unsigned char *)s1 == *(unsigned char *)s2)
	{
		if (n == 0)
		{
			return (0);
		}
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
