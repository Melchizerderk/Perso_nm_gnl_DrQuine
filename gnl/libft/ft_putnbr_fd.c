/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:38:23 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:38:09 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (fd)
	{
		str = ft_itoa(n);
		while (*str != '\0')
		{
			write(fd, str, 1);
			str++;
		}
	}
}
