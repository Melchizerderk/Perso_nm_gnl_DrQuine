/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:07:18 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/26 16:13:34 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
 #define NM_OTOOL_H

#define ERROR1 "error: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/nm: can't open file: a.out (No such file or directory\n)"
#define ERROR2 "Invalid command, check your syntax\n"
#define PERMERROR "Invalid right or non existant file\n"
#define MUNMAP_ERR "Munmap Failed\n"
#define DEFAULT_N_VALUE	"0000000100000000"
#define S_DEFAULT_N_VALUE "0000000000000000"
#define FILETYPE_ERRORP1 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/nm: "
#define FILETYPE_ERRORP2 " The file was not recognized as a valid object file."
#define BLANK "                "

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/ranlib.h>

#include "libft/libft.h"

void 	ft_nmmapping(int fd, char *path);
void 	ft_nm_handle64(char *map_ptr, int ostype);
char	*ft_convert(int n_value, int filetype, int ostype);
t_list	*ft_sort(int nsyms, char *strtable, struct nlist_64 *array, t_list *lst_sym);

typedef struct	s_datamacho {
				
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	char					*strtable;
	struct nlist_64			*array;
}				t_datamacho;

#endif
