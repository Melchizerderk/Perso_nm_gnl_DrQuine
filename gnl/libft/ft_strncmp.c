/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:34:11 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:25:28 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 1 && (*s1 == *s2) && (*s1 && *s2))
	{
		s1++;
		s2++;
		n--;
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	return (*s1 - *s2);
}
