/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 12:44:54 by bcrespin          #+#    #+#             */
/*   Updated: 2016/02/07 12:56:52 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcut(char **str, int start, int lenght)
{
	int i;
	char *tmp;
	char *tmp2;

	tmp = malloc(sizeof(char) * lenght);
	i = 0;
	tmp2 = *str;
	while(i <= start)
		*str++;
	ft_strncpy(tmp, *str, lenght);
	ft_strsub(*str, start, lenght);
	return (tmp);
}
