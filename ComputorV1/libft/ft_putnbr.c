/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:12:06 by bcrespin          #+#    #+#             */
/*   Updated: 2014/10/07 17:30:51 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void ft_putnbr(int n)
{
	char	*str;

	if (n == 0)
		write(1, "0", 1);
	else
	{
		str = ft_itoa(n);
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
	}
}
