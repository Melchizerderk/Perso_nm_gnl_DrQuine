/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:59:47 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:23:32 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *stemp;

	stemp = s1;
	while (*stemp != '\0')
		stemp++;
	while (n && *s2)
	{
		*stemp = *s2;
		stemp++;
		s2++;
		n--;
	}
	*stemp = '\0';
	return (s1);
}
