/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:40:28 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:32:43 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t sizecr;

	sizecr = 0;
	while (*dst != '\0')
	{
		dst++;
		sizecr++;
	}
	while (size > 0)
	{
		*dst = *(char*)src;
		dst++;
		src++;
		sizecr++;
		size--;
	}
	return (sizecr);
}
