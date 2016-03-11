/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:17:58 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/11 19:26:42 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char *ft_convert(int n_value)
{
 	return NULL;
}

t_list	*ft_sort(int nsyms, char *strtable, struct nlist_64 *array, t_list *lst_sym)
{
	int i;
	t_list *tmp;

	i = 0;	
	while (i < nsyms)
	{
		if (i == 0)
			lst_sym = putback_elemd(lst_sym, ft_itoa(i));
		else
		{
			tmp = lst_sym;
			while (tmp != NULL)
			{
				if (ft_strcmp((strtable + array[ft_atoi(tmp->data)].n_un.n_strx), (strtable + array[i].n_un.n_strx)) <= 0)
				{
					if (tmp->next != NULL)
					{
						if (ft_strcmp((strtable + array[ft_atoi(tmp->next->data)].n_un.n_strx), \
									(strtable + array[i].n_un.n_strx)) >= 0)
							putafterbefore_elemd(tmp->next, ft_itoa(i), 1);
					}
					putafterbefore_elemd(tmp, ft_itoa(i), 1);
					break ;
				}
				else
				{
					putafterbefore_elemd(tmp, ft_itoa(i), -1);
					break ;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (lst_sym);
}

void print_symb(int nsyms, int symoff, int stroff, char *map_ptr)
{
        int                     i;
        char                    *strtable;
        struct  nlist_64        *array;
		t_list					*lst_sym;

        array = (void *)map_ptr + symoff;
        strtable = (void *)map_ptr + stroff;
        i = 0;
		lst_sym = ft_sort(nsyms, strtable, array, lst_sym);
        while (lst_sym != NULL)
        {
			printf("%s\n", lst_sym->data);
			ft_putstr(strtable + array[ft_atoi(lst_sym->data)].n_un.n_strx); //nom du flag en 3e
		//a tester
			write(1, "\n", 1);
		//	ft_putstr(strtable + array[i].n_type); //type de flag (T,U etc) en 2e
		/*	write(1, " ", 1);
			ft_putstr(strtable + array[i].n_sect); //numero de section en 1er
			write(1, " ", 1);
			ft_putstr(strtable + array[i].n_desc); //a voir pas sur
		*///	write(1, " ", 1);
		//	printf("%llx\n", array[i].n_value);
		//	ft_putnbr(array[i].n_value); //a voir pas sur
		//	write(1, " ", 1);
			lst_sym = lst_sym->next;
		}
}

void ft_nm_handle64(char *map_ptr)
{
        int                     nbcmds;
        int                     i;
        struct mach_header_64   *header;
        struct load_command     *lc;
        struct symtab_command   *sym;

        i = 0;
        header = (struct mach_header_64 *) map_ptr;
        nbcmds = header->ncmds;
        lc = (void *)map_ptr + sizeof(*header);
        while (i < nbcmds)
        {
                if (lc->cmd == LC_SYMTAB)
                {
                        sym = (struct symtab_command *) lc;
                        print_symb(sym->nsyms, sym->symoff, \
                                sym->stroff, map_ptr);
                        break;
                }
                lc = (void *)lc + lc->cmdsize;
                i++;
        }
}
