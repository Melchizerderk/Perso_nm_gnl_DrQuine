/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:39:46 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:26:45 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while ((char)*s != '\0')
	{
		s++;
		i++;
	}
	if ((char)c == '\0')
		return ((char*)s);
	while (i > 0)
	{
		if ((char)*s == (char)c)
			return ((char*)s);
		i--;
		s--;
	}
	return (NULL);
}
