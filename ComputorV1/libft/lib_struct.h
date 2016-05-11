/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 19:31:35 by bcrespin          #+#    #+#             */
/*   Updated: 2014/11/12 17:03:47 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_STRUCT_H
# define LIB_STRUCT_H

# include <string.h>
# include <stdlib.h>

typedef struct	s_strsplit
{
	int		i;
	int		e;
	char	**tabtemp;
	char	**tab;
}				t_split;

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
	struct s_list	*prev;
	int				cur_pos;
	int				underline;
	int				head;
}				t_list;

#endif
