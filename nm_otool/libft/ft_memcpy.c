/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:00:17 by bcrespin          #+#    #+#             */
/*   Updated: 2013/12/24 13:51:10 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void *ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char *stemp;

	stemp = (unsigned char*)s1;
	while (n > 0)
	{
		*stemp = *(unsigned char*)s2;
		n--;
		stemp++;
		s2++;
	}
	return (s1);
}
