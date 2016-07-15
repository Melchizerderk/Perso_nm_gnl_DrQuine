/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:40:10 by bcrespin          #+#    #+#             */
/*   Updated: 2013/12/29 15:24:39 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *s1, const char *s2)
{
	char	*stemp;

	stemp = s1;
	if (ft_strlen(s1) < ft_strlen(s2))
	{
		ft_putstr("! s1 too short !");
		return (s1);
	}
	while (*stemp != '\0')
		stemp++;
	while (*s2 != '\0')
	{
		*stemp = *s2;
		stemp++;
		s2++;
	}
	stemp++;
	stemp = '\0';
	return (s1);
}
