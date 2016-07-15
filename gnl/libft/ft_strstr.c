/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:56:58 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:31:40 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*stemp;
	int			i;

	if (*s2 == '\0')
		return ((char*)s1);
	i = ft_strlen(s2);
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
		{
			stemp = s1;
			while (i > 0)
			{
				if (ft_memcmp(s1, s2, i) != 0)
					return (NULL);
				else
					s2++;
				s1++;
				i--;
			}
			return ((char*)stemp);
		}
		s1++;
	}
	return (NULL);
}
