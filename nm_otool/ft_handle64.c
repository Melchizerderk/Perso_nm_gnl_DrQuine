/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:17:58 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/24 14:56:37 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_list	*ft_sort_swap(int *d, t_list *tmp, char *strtable, struct nlist_64 *array)
{
	char *tdata;

	tdata = NULL;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(strtable + array[ft_atoi(tmp->data)].n_un.n_strx, \
					strtable + array[ft_atoi(tmp->next->data)].n_un.n_strx) > 0)
		{
			*d = 0;
			tdata = ft_strdup(tmp->data);
			tmp->data = ft_strcpy(tmp->data, tmp->next->data);
			tmp->next->data = ft_strcpy(tmp->next->data, tdata);
			free(tdata);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

t_list	*ft_sort(int nsyms, char *strtable, struct nlist_64 *array, t_list *lst_sym)
{
	int i;
	int d;
	t_list *tmp;
	
	d = 0;
	i = 0;
	while (i < nsyms)
	{
		lst_sym = putback_elemd(lst_sym, ft_itoa(i));
		i++;
	}
	while (d == 0)
	{
		tmp = lst_sym;
		d = 1;
		tmp = ft_sort_swap(&d, tmp, strtable, array);
	}
	return (lst_sym);
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
			if (ft_strcmp(strtable + array[ft_atoi(lst_sym->data)].n_type, "header") == 0)
			{
				ft_putstr(ft_convert(array[ft_atoi(lst_sym->data)].n_value, filetype));
				write(1, " T ", 3);
			}
			else if (filetype == 2)
			{
				if (ft_strcmp(strtable + array[ft_atoi(lst_sym->data)].n_type, "header") == 0 || \
						ft_atoi(lst_sym->data) == 0)
				{
					ft_putstr(ft_convert(array[ft_atoi(lst_sym->data)].n_value, filetype));
					write(1, " T ", 3);
				}
				else
				{
					write(1, BLANK, 16);
					write(1, " U ", 3);
				}
			}
			else
			{
				write(1, BLANK, 16);
				write(1, " U ", 3);
			}
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

void ft_nm_handle64(char *map_ptr, int filetype)
{
        int			nbcmds;
        int			i;
		t_datamacho	data;

        i = 0;
        data.header = (struct mach_header_64 *) map_ptr;
        nbcmds = data.header->ncmds;
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
