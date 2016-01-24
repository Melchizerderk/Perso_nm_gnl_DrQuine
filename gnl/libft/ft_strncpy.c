/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:23:23 by bcrespin          #+#    #+#             */
/*   Updated: 2016/01/24 17:23:56 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, int n)
{
	int i;

	i = 0;
	if (!n)
		return (NULL);
	while (i < n)
	{
		while (s2[i] && i < n)
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
		i++;
	}
	return (s1);
}
