/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:17:58 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/26 13:04:26 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void	ft_print_aout(char *strtbl, struct nlist_64 *array, t_list *lst_sym, int ft)
{
	if (ft_strcmp(strtbl + array[ft_atoi(lst_sym->data)].n_type, "header") == 0)
	{
		ft_putstr(ft_convert(array[ft_atoi(lst_sym->data)].n_value, ft));
		write(1, " T ", 3);
	}
	else
	{
		write(1, BLANK, 16);
		write(1, " U ", 3);
	}
}

void	ft_print_o(char *strtbl, struct nlist_64 *array, t_list *lst_sym, int ft)
{

	if (ft_strcmp(strtbl + array[ft_atoi(lst_sym->data)].n_type, "header") == 0 || \
			array[ft_atoi(lst_sym->data)].n_sect == 1)
	{
		ft_putstr(ft_convert(array[ft_atoi(lst_sym->data)].n_value, ft));
		write(1, " T ", 3);
	}
	else if (array[ft_atoi(lst_sym->data)].n_sect == 2)
	{
		ft_putstr(ft_convert(array[ft_atoi(lst_sym->data)].n_value, ft));
		write(1, " b ", 3);
	}
	else
	{
		write(1, BLANK, 16);
		write(1, " U ", 3);
	}
}

void print_symb(t_datamacho data, char *map_ptr, int filetype)
{
        char                    *strtable;
        struct  nlist_64        *array;
		t_list					*lst_sym;

        array = (void *)map_ptr + data.sym->symoff;
        strtable = (void *)map_ptr + data.sym->stroff;
		lst_sym = NULL;
		lst_sym = ft_sort(data.sym->nsyms, strtable, array, lst_sym);
        while (lst_sym != NULL)
        {
			if (filetype == 2)
				ft_print_aout(strtable, array, lst_sym, filetype);
			else if (filetype == 1)
				ft_print_o(strtable, array, lst_sym, filetype);
			ft_putstr(strtable + array[ft_atoi(lst_sym->data)].n_un.n_strx); //nom du flag en 3e
		//a tester
			write(1, "\n", 1);
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
		int			filetype;
		t_datamacho	data;

        i = 0;
        data.header = (struct mach_header_64 *) map_ptr;
        nbcmds = data.header->ncmds;
		filetype = data.header->filetype;
        data.lc = (void *)map_ptr + sizeof(*(data.header));
        while (i < nbcmds)
        {
                if (data.lc->cmd == LC_SYMTAB)
                {
                        data.sym = (struct symtab_command *) data.lc;
						print_symb(data, map_ptr, filetype);
                        break;
                }
                data.lc = (void *)data.lc + data.lc->cmdsize;
                i++;
        }
}
