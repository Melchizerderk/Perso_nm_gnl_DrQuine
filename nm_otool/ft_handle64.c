/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:17:58 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/23 16:10:38 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char *ft_convert_hexa(char *str)
{
	int n;
	char *value;

	value = malloc(sizeof(char) * 1);
	n = ft_atoi(str);
	if (n == 10)
		value = "a";
	if (n == 11)
		value = "b";
	if (n == 12)
		value = "c";
	if (n == 13)
		value = "d";
	if (n == 14)
		value = "e";
	if (n == 15)
		value = "f";
	str = ft_strdup(value);
	return (str);
}

char *ft_convert(int n_value)
{
	int 	r;
	int		i;
	char	*v_string;
	t_list	*conv_lst;	

	i = 0;
	conv_lst = NULL;
	v_string = ft_strdup(DEFAULT_N_VALUE);
	while (n_value != 0)
	{
		r = n_value % 16;
		n_value = n_value / 16;
		conv_lst = putfront_elemd(conv_lst, ft_itoa(r));
		i++;
	}
	i = 16 - i;
	v_string = ft_strsub(v_string, 0, i);
	while (conv_lst != NULL)
	{
		if (ft_atoi(conv_lst->data) > 9)
			conv_lst->data = ft_convert_hexa(conv_lst->data);
		else if (ft_atoi(conv_lst->data) == 0)
			conv_lst->data = "0";
		v_string = ft_strjoin(v_string, conv_lst->data);
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
	
	d = 0;
	i = 0;
	tdata = NULL;
	while (i < nsyms)
	{
		lst_sym = putback_elemd(lst_sym, ft_itoa(i));
		i++;
	}
	while (d == 0)
	{
		tmp = lst_sym;
		d = 1;
		while (tmp->next != NULL)
		{
			if (ft_strcmp(strtable + array[ft_atoi(tmp->data)].n_un.n_strx, \
						strtable + array[ft_atoi(tmp->next->data)].n_un.n_strx) > 0)
			{
				d = 0;
				tdata = ft_strdup(tmp->data);
				tmp->data = ft_strcpy(tmp->data, tmp->next->data);
				tmp->next->data = ft_strcpy(tmp->next->data, tdata);
				free(tdata);
			}
			tmp = tmp->next;
		}
	}
	tmp = lst_sym;
	return (lst_sym);
}

void print_symb(int nsyms, int symoff, int stroff, char *map_ptr)
{
        char                    *strtable;
        struct  nlist_64        *array;
		t_list					*lst_sym;

        array = (void *)map_ptr + symoff;
        strtable = (void *)map_ptr + stroff;
		lst_sym = NULL;
		lst_sym = ft_sort(nsyms, strtable, array, lst_sym);
        while (lst_sym != NULL)
        {
			printf("%llx\n", array[ft_atoi(lst_sym->data)].n_value);
			ft_putstr(ft_convert(array[ft_atoi(lst_sym->data)].n_value));
			write(1, "  ", 2);
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
