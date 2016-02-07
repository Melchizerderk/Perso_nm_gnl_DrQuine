/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:28:06 by bcrespin          #+#    #+#             */
/*   Updated: 2014/02/04 15:40:01 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void ft_putendl_fd(char const *s, int fd)
{
	if (fd)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
