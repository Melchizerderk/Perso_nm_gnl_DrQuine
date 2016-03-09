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

void print_output(int nsyms, int symoff, int stroff, char *map_ptr)
{
	int 			i;
	char 			*strtable;
	struct	nlist_64 	*arrat;
	
	array = (void *)map_ptr + symoff;
	strtable = (void *)map_ptr + stroff;	
	i = 0;
	while (i < nsyms)
	{
		ft_putstr(strtable + array[i].n_un.n_strx);
		i++;		
	}
}

void ft_nm_handle64(char *map_ptr)
{
	int			nbcmds;
	int			i;
	struct mach_header_64 	*header;
	struct load_command	*lc;
	struct symtab_command	*sym;
	
	i = 0;
	header = (struct mach_header_64 *) map_ptr;
	nbcmds = header->ncmds;
	lc = (void *)map_ptr + sizeof(*header);
	while (i < nbcmds)
	{
		if (lc->cmd = LC_SYMTAB)
		{
			sym = (struct symtab_command *) lc;
			print_output(sym->nsyms, sym->symoff, sym->stroff, map_ptr);
			break;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;	
	}
}

void ft_nmprint(char *map_ptr)
{
	int m_number;

	m_number = *(int *) map_ptr;
	if (m_number = MH_MAGIC_64)
	{
		ft_nm_handle64(ptr);
		//fichier de 64 bits
		//faut-il gerer le 32?
	}
}


void ft_nmmapping(int fd)
{
	char *map_ptr;
	struct stat buf;
	
	map_ptr = NULL;
	if (fstat(fd, &buf) >= 0)
	{
		if (map_ptr = mmap(0, buf.st_size, PROT_READ, MAP_SHARED, fd, 0) \ 
			!= MAP_FAILED)
		{
			ft_nmprint(map_ptr);
			if (munmap(ptr, buf.st_size) < 0)
				ft_putstr(MUNMAP_ERROR);
		}
	}
}
