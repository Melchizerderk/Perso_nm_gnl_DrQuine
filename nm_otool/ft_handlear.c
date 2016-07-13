/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 17:13:47 by bcrespin          #+#    #+#             */
/*   Updated: 2016/05/26 11:47:42 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void	ft_nm_handleAr(char *map_ptr)
{
	struct ranlib	*header;
	struct ar_hdr	*test;
	char			*strtable;
	struct ranlib	*array;
#ifdef __LP64__
	undefine LP64
#endif
	test = (struct ar_hdr *)map_ptr;
	header = (struct ranlib *)map_ptr;
	array = (void *)map_ptr + header->ran_un.ran_strx;
	strtable = (void *)map_ptr + header->ran_off;
	/*printf("%s\n", test->ar_name);
	printf("%s\n", test->ar_date);
	printf("%s\n", test->ar_uid);
	printf("%s\n", test->ar_gid);
	printf("%s\n", test->ar_mode);
	printf("%s\n", test->ar_size);
	printf("%s\n", test->ar_fmag + 1);*/
//	printf("%s\n", header->ran_off + header->ran_un.ran_name);
}
