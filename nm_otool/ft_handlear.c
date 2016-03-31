/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 17:13:47 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/31 18:14:44 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void	ft_nm_handleAr(char *map_ptr)
{
	struct ranlib	*header;

	header = (struct ranlib *)map_ptr;
	map_ptr = map_ptr + header.ran_off;
}
