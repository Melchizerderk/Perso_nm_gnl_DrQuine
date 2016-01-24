/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:48:35 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/13 17:21:21 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char *stemp;

	stemp = (char*)malloc(n * sizeof(char));
	ft_strncpy((char*)stemp, s1, n);
	return (ft_strstr(stemp, s2));
}
