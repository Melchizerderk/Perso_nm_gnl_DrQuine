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
	int 	r;
	char	*v_string;
	t_list	conv_lst;	

	while (n_value != 0)
	{
		n_value = n_value / 16;
		r = n_value % 16;
		r = r * 16;
		r = putfront_elemd(conv_lst, ft_itoa(r));
	}
	while (conv_lst != NULL)
	{
		if (conv_lst->ft_atoi(data) > 9)
			conv_lst->data = conv_lst->(data + 23);
		v_string = strjoin(v_string, conv_lst->data);
		conv_lst = conv_lst->next;
	}
 	return (v_string);
}

t_list	*ft_sort(int nsyms, char *strtable, struct nlist_64 *array, t_list *lst_sym)
{
	int i;
	int d;
	char *tdata;
	t_list *tmp;

	i = 0;
	tdata = NULL;
	while (i < nsyms)
	{
		lst_sym = putbackelemd(lst_sym, ft_itoa(i));
		i++;
	}
	while (d = 0)
	{
		tmp = lst_sym;
		i = 0;
		d = 1;
		while (i < nsyms)
		{
			if (ft_strcmp(strtable + array[ft_atoi(tmp->data)], strtable + array[ft_atoi(tmp->next->data)]) > 0)
			{
				d = 0;
				tdata = ft_strdup(tmp->data);
				tmp->data = ft_strcpy(tmp->next->data);
				tmp->next->data = ft_strcpy(tdata);
				free(tdata);
			}
			i++;	
		}
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
		ft_putstr(ft_convert(strtable + array[lst_sym->data].n_un.n_strx));
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
