/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:04:44 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/26 16:14:13 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char	*ft_convert_hexa(char *str)
{
	int 	n;
	char 	*value;

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

char	*ft_sub_convert(char *v_string, int n_value)
{
	int 	r;
	int 	i;
	t_list	*conv_lst;

	i = 0;
	conv_lst = NULL;
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

char	*ft_convert(int n_value, int filetype, int ostype)
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
