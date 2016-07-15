/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:27:12 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:42:45 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void ft_bzero(void *s, size_t n)
{
	while (n > 0 && *(char*)s != '\0')
	{
		*(char *)s = '0';
		s++;
		n--;
	}
}
