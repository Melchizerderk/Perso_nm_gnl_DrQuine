/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 15:37:51 by bcrespin          #+#    #+#             */
/*   Updated: 2014/01/11 15:36:05 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int		val;
	char	**tab;

	tmp = (char **)malloc((ft_strlen(s) + 1) * sizeof(char *));
	tab = tmp;
	while (*s != '\0' && tmp != NULL)
	{
		if (*s != c)
		{
			if ((val = ft_strchr(s, c) - s) > 0 && val <= (int)ft_strlen(s))
			{
				*tmp++ = (char *)ft_strndup(s, val);
				s = s + (val);
			}
			else
			{
				*tmp++ = ft_strdup(s);
				*tmp = 0;
				return (tab);
			}
		}
		s++;
	}
	return (tab);
}
