/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:12:55 by bcrespin          #+#    #+#             */
/*   Updated: 2014/01/09 16:24:40 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *s;

	s = malloc(sizeof(char) * (size + 1));
	if (s)
	{
		while (size + 1)
		{
			s[size] = 0;
			size--;
		}
	}
	return (s);
}
