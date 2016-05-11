/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:48:03 by bcrespin          #+#    #+#             */
/*   Updated: 2016/01/24 18:04:58 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strcpy(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = (char)s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}
