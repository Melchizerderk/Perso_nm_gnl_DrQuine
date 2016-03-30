/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:07:18 by bcrespin          #+#    #+#             */
/*   Updated: 2016/03/30 16:40:01 by bcrespin         ###   ########.fr       */
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
#define DYLD "dyld_stub_binder"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/ranlib.h>
#include <ar.h>
#include "libft/libft.h"

typedef struct	s_datamacho {
				
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	char					*strtable;
	struct nlist_64			*array;
}				t_datamacho;

typedef struct 	s_listnmo {
	
	int					data;
	struct s_listnmo 	*next;
	struct s_listnmo 	*prev;

}				t_listnmo;

t_listnmo	*ft_sort(int nsyms, char *strtable, struct nlist_64 *array, t_listnmo *lst_sym);
void 		ft_nmmapping(int fd, char *path);
void 		ft_nm_handle64(char *map_ptr);
char		*ft_convert(int n_value, int filetype);
t_listnmo	*put_elem_back(t_listnmo *new_list, int data);
t_listnmo	*put_elem_front(t_listnmo *new_list, int data);

#endif
