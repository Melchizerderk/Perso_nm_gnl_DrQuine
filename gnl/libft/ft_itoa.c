/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 16:32:21 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:39:51 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		nt;

	nt = n;
	i = 0;
	while (nt != 0)
	{
		nt = (nt / 10);
		i++;
	}
	str = (char*)malloc((i + 1) * sizeof(char));
	*(str + i) = '\0';
	while (*str != '\0')
		str++;
	while (i > 0)
	{
		str--;
		nt = (n % 10);
		n = (n / 10);
		*str = 48 + nt;
		i--;
	}
	return (str);
}
