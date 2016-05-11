/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:23:36 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:39:14 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void *ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*stemp;

	stemp = NULL;
	if (s1 <= s2)
		return (ft_memcpy(s1, s2, n));
	while (n > 0)
	{
		*(char *)stemp = *(char *)s2;
		s2++;
		stemp++;
		n--;
	}
	return (s1);
}
