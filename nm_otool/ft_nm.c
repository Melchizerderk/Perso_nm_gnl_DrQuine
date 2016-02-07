/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:49:38 by bcrespin          #+#    #+#             */
/*   Updated: 2016/02/07 15:47:12 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void ft_nmprint(int fd)
{
	void *map_ptr;
	struct stat buf;

	map_ptr = mmap(0, 32, PROT_READ, MAP_SHARED, fd, 0);
	perror(NULL);
	fstat(fd, &buf);
	perror(NULL);
//	printf("%s", map_ptr);
}
