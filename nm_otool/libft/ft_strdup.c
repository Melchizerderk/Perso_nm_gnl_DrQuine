/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:54:45 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:34:39 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if (s1 != NULL)
	{
		s2 = malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
		ft_strcpy(s2, (char *)s1);
		return (s2);
	}
	return (NULL);
}
