/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 14:36:25 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:30:28 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *s2;

	if (s1 != NULL)
	{
		if (ft_strlen((char *)s1) < n)
		{
			ft_putstr("n longer than s1");
			return (0);
		}
		s2 = malloc((n + 1) * sizeof(char));
		ft_strncpy(s2, s1, n);
		return (s2);
	}
	return (NULL);
}
