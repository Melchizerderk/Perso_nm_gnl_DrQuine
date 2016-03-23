/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:07:18 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/23 16:26:05 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
 #define NM_OTOOL_H

#define ERROR1 "error: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/nm: can't open file: a.out (No such file or directory\n)"
#define ERROR2 "Invalid command, check your syntax\n"
#define PERMERROR "Invalid right or non existant file\n"
#define MUNMAP_ERR "Munmap Failed\n"
#define DEFAULT_N_VALUE	"0000000100000000"
#define BLANK "                "

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>

#include "libft/libft.h"

void ft_nmmapping(int fd);
void ft_nm_handle64(char *map_ptr);

#endif
