/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:12:06 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/16 17:38:25 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putnbr(int n)
{
	if (n <= INT_MAX && n >= INT_MIN)
	{
		if (n >= 10)
		{
			if (n >= 10)
				return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
			else
				return (ft_putchar('0' + n));
		}
		else
			return (ft_putchar('_') + ft_putnbr(-n));
	}
	else if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	return (0);
}
