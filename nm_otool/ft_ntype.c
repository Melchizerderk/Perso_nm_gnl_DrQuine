/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:30:03 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/31 16:27:00 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char	ft_nsect_value(uint8_t n_sect, char symbol)
{
	if (n_sect == 1)
		symbol = 'T';
	else if (n_sect == 2)
		symbol = 'B';
	else if (n_sect == 0)
		symbol = 'U';
	return (symbol);
}

char	ft_ntype_value(uint8_t ntype, uint8_t n_sect)
{
	char symbol;

	symbol = 'R';
	if (ntype == N_STAB)
		symbol = 'N';
	//else if (ntype == N_PEXT) a voir pas sur de l'output que cela doit produire
		//?
	else 
	{
		if (N_TYPE == N_UNDF)
			symbol = 'U';
		else if (N_TYPE == N_ABS)
			symbol = 'A';
		else if (N_TYPE == N_SECT)
			symbol = ft_nsect_value(n_sect, symbol);
		else if (N_TYPE == N_PBUD)
			symbol = 'U';
		else if (N_TYPE == N_INDR)
			symbol = 'I';
	}
	if (ntype == N_EXT)
		symbol = symbol + 32;
	return (symbol);
}
