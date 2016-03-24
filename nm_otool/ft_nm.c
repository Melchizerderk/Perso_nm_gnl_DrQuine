/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:49:38 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/24 18:12:56 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void ft_nmprint(char *map_ptr, char *path)
{
	unsigned int m_number;
	struct mach_header_64 *header;
	
	header = (struct mach_header_64 *)map_ptr;
	m_number = *(unsigned int *) map_ptr;
	if (m_number == MH_MAGIC_64)
	{
		ft_nm_handle64(map_ptr);
		//fichier de 64 bits
		//faut-il gerer le 32?
	}
	printf("%d\n", MH_DYLIB);
	if (header->filetype == MH_DYLIB)
		printf("lib\n");
	else
	{
		ft_putstr(FILETYPE_ERRORP1);
		ft_putstr(path);
		ft_putstr(FILETYPE_ERRORP2);
		write(1, "\n", 1);
	}
}


void ft_nmmapping(int fd, char *path)
{
	char *map_ptr;
	struct stat buf;
	
	map_ptr = NULL;
	if (fstat(fd, &buf) >= 0)
	{
		if ((map_ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) \
				!= MAP_FAILED)
		{
			ft_nmprint(map_ptr, path);
			if (munmap(map_ptr, buf.st_size) < 0)
				ft_putstr(MUNMAP_ERR);
		}
	}
}
