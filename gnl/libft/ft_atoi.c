/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:38:35 by bcrespin          #+#    #+#             */
/*   Updated: 2016/07/20 14:02:17 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int resul;
	int nega;

	resul = 0;
	nega = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\v'
				|| *str == '\n' || *str == '\r' || *str == '\f'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		nega = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		resul = (resul * 10) + (*str++ - '0');
	return (resul * nega);
}
