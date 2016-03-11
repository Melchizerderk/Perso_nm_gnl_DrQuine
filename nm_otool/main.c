/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:03:42 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/11 13:21:08 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include <fcntl.h>

void ft_nm(char *arg)
{
	char 	*filename;
	int		fd;

	if (arg == NULL)	
	{
		if ((fd = open("a.out", O_RDONLY)) == -1)
			write(1, ERROR1, 100);
		else
			ft_nmmapping(fd);
	}
	else
	{
		if ((fd = open(arg, O_RDONLY)) == -1)
			write(1, PERMERROR, 34);
		ft_nmmapping(fd);
	}
}

int main (int ac, char **av)
{
	if (ac == 1)
	{
		ft_nm(NULL);
	}
	if (ac == 2)
	{
		ft_nm(av[1]);
	}
	return (0);
}
