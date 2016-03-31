/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:17:58 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/31 16:23:51 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void	ft_print_exec(t_datamacho data, t_listnmo *lst_sym, int ft)
{
	if (data.array[lst_sym->data].n_sect == NO_SECT)
	{
		write(1, BLANK, 16);
		write(1, " U ", 3);
	}
	else
	{
		ft_putstr(ft_convert(data.array[lst_sym->data].n_value, ft));
		write(1, " ", 1);
		ft_putchar(ft_ntype_value(data.array[lst_sym->data].n_type, \
				data.array[lst_sym->data].n_sect));
		write(1, " ", 1);
	}
	ft_putstr(data.strtable + data.array[lst_sym->data].n_un.n_strx);
	write(1, "\n", 1);
}

void	ft_print_o(t_datamacho data, t_listnmo *lst_sym, int ft)
{
	if (data.array[lst_sym->data].n_sect == NO_SECT)
	{
		write(1, BLANK, 16);
		write(1, " U ", 3);
	}
	else
	{
		ft_putstr(ft_convert(data.array[lst_sym->data].n_value, ft));
		write(1, " ", 1);
		ft_putchar(ft_ntype_value(data.array[lst_sym->data].n_type, \
				data.array[lst_sym->data].n_sect));
		write(1, " ", 1);
	}
	ft_putstr(data.strtable + data.array[lst_sym->data].n_un.n_strx); //nom du flag en 3e
	write(1, "\n", 1);
}

void print_symb(t_datamacho data, char *map_ptr, int filetype)
{
		t_listnmo				*lst_sym;

        data.array = (void *)map_ptr + data.sym->symoff;
        data.strtable = (void *)map_ptr + data.sym->stroff;
		lst_sym = NULL;
		lst_sym = ft_sort(data.sym->nsyms, data.strtable, data.array, lst_sym);
        while (lst_sym != NULL)
        {
			if (filetype == 2)
				ft_print_exec(data, lst_sym, filetype);
			else if (filetype == 1)
				ft_print_o(data, lst_sym, filetype);
		//a tester
		/*	ft_putstr(strtable + array[i].n_desc); //a voir pas sur
		*///	write(1, " ", 1);
		//	printf("%llx\n", array[i].n_value);
		//	ft_putnbr(array[i].n_value); //a voir pas sur
		//	write(1, " ", 1);
			lst_sym = lst_sym->next;
		}
}

void ft_nm_handle64(char *map_ptr)
{
        int			nbcmds;
        int			i;
		t_datamacho	data;

        i = 0;
        data.header = (struct mach_header_64 *)map_ptr;
        nbcmds = data.header->ncmds;
        data.lc = (void *)map_ptr + sizeof(*(data.header));
        while (i < nbcmds)
        {
                if (data.lc->cmd == LC_SYMTAB)
                {
                        data.sym = (struct symtab_command *) data.lc;
						print_symb(data, map_ptr, data.header->filetype);
                        break;
                }
                data.lc = (void *)data.lc + data.lc->cmdsize;
                i++;
        }
}
