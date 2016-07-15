/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:48:36 by bcrespin          #+#    #+#             */
/*   Updated: 2016/07/13 17:05:41 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_keepreading(const int fd, int *i, int **readreturn)
{
	char *temp;
	char *buf;

	temp = malloc(sizeof(char) * BUFF_SIZE);
	buf = malloc(sizeof(char) * BUFF_SIZE);
	**readreturn = read(fd, buf, BUFF_SIZE);
	if (**readreturn == -1 || **readreturn == 0)
		return (NULL);
	*i = ft_findchar(buf, '\n');
	while (*i == -1)
	{
		**readreturn = read(fd, temp, BUFF_SIZE);
		buf = ft_strdup(ft_strjoin(buf, temp));
		*i = ft_findchar(buf, '\n');
	}
	free(temp);
	return (buf);
}

char *ft_tosaveornot(char **buf, int i, char *savedread)
{
	int d;

	if (i == ft_strlen(*buf))
	{
		*buf = ft_strsub(*buf, 0, ft_strlen(*buf) - 1); /*pour enlever le backslash n*/
		return (NULL);
	}
	if (i <	ft_strlen(*buf))
	{
		if (savedread)
			d = ft_strlen(savedread) + i;
		else
			d = i;
		savedread = ft_strdup(*buf);
		savedread = ft_strsub(savedread, d, ft_strlen(savedread));
		*buf = ft_strsub(*buf, 0, d - 1);
		return (savedread);
	}
	return (NULL);
}

char *ft_read(const int fd, char **savedread, int readstatus, int *readreturn)
{
	char	*buf;
	int	i;

	if (readstatus == 0)
	{
		buf = ft_strdup(ft_keepreading(fd, &i, &readreturn));
		if (buf == NULL)
			return (NULL);
		*savedread = ft_tosaveornot(&buf, i, *savedread);
	}
	if (readstatus == 1)
	{
		i = ft_findchar(*savedread, '\n');
		if (i == -1)
		{
			buf = ft_strdup(ft_keepreading(fd, &i, &readreturn));
			if (buf == NULL)
				return (NULL);
			buf = ft_strjoin(*savedread, buf);
			*savedread = ft_tosaveornot(&buf, i, *savedread);
		}
		else
		{
			buf = ft_strdup(*savedread);
			buf = ft_strsub(buf, 0, i - 1);
			*savedread = ft_strsub(*savedread, i, ft_strlen(*savedread));
		}
	}
	return (buf);
}

int get_next_line(const int fd, char **line)
{
	static char *savedread;
	int readstatus;
	int readreturn;
	int d;
	
	d = 0;
	if (!savedread)
		readstatus = 0;
	else if (ft_strlen(savedread) < BUFF_SIZE)
	{
		printf("Ce qui a ete saved precedemment : %s\n", savedread);
		readstatus = 1;
	}
	*line =	ft_read(fd, &savedread, readstatus, &readreturn);
	if (savedread)
		d = ft_strlen(savedread);
	if (readreturn > 0 || d != 0)
		return (1);
	else if (readreturn == -1)
		return (-1);
	return (0);
}
