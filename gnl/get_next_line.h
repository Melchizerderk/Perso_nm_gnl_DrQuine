/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:48:51 by bcrespin          #+#    #+#             */
/*   Updated: 2016/07/13 15:37:52 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 50
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft42/libft.h"
#include <stdio.h>

int get_next_line(const int fd, char **line);
