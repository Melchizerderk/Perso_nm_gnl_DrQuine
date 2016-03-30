/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:04:44 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/30 16:48:34 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char	ft_convert_hexa(int n)
{
	char 	value;

	if (n == 10)
		value = 'a';
	if (n == 11)
		value = 'b';
	if (n == 12)
		value = 'c';
	if (n == 13)
		value = 'd';
	if (n == 14)
		value = 'e';
	if (n == 15)
		value = 'f';
	return (value);
}

char	*ft_sub_convert(char *v_string, int n_value)
{
	int 	r;
	int 		i;
	t_listnmo	*conv_lst;

	i = 0;
	conv_lst = NULL;
	while (n_value != 0)
	{
		r = n_value % 16;
		n_value = n_value / 16;
		conv_lst = put_elem_front(conv_lst, r);
		i++;
	}
	i = 16 - i;
	v_string = ft_strsub(v_string, 0, i);
	while (conv_lst != NULL)
	{
		if (conv_lst->data > 9)
			v_string = ft_strjoin(v_string, ft_itoa(ft_convert_hexa(conv_lst->data)));
		else if (conv_lst->data == 0)
			v_string = ft_strjoin(v_string, "0");
		else
			v_string = ft_strjoin(v_string, ft_itoa(conv_lst->data));
		conv_lst = conv_lst->next;
	}
	return (v_string);
}

char	*ft_convert(int n_value, int filetype)
{
	char *v_string;

	v_string = NULL;
	if (filetype == 2)
		v_string = ft_strdup(DEFAULT_N_VALUE);
	else if (filetype == 1)
		v_string = ft_strdup(S_DEFAULT_N_VALUE);
	v_string = ft_sub_convert(v_string, n_value);
	return (v_string);
}
