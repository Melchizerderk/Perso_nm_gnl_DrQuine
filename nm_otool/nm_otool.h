/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:07:18 by bcrespin          #+#    #+#             */
/*   Updated: 2016/02/07 14:40:06 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
 #define NM_OTOOL_H

#define ERROR1 "error: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/nm: can't open file: a.out (No such file or directory\n)"
#define ERROR2 "Invalid command, check your syntax\n"
#define PERMERROR "Invalid right or non existant file\n"
#define MUNMAP_ERR "Munmap Failed\n"

#define PROMPT "$> "
#define MAP_LEN 2

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>

#include "libft/libft.h"

void ft_nmmapping(int fd);

#endif
