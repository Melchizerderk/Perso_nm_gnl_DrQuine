/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:03:42 by bcrespin          #+#    #+#             */
/*   Updated: 2016/02/07 15:19:03 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"
#include <fcntl.h>

int have_space(char *line)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(line))
	{
		if (line[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void ft_nm(char *line)
{
	char 	*filename;
	int		fd;

	if (ft_strcmp(line, "nm") == 0)	
	{
		fd = open("a.out", O_RDONLY);
		printf("%d\n", fd);
		if (fd == -1)
		{
			write(1, ERROR1, 100);
		}
		else
			ft_nmprint(fd);
	}
	else if (ft_strlen(line) > 2 && have_space(line) == 0) 
		write(1, ERROR2, 34);	
	else
	{
		while (*line != ' ')
			line++;
		line++;
		filename = malloc(sizeof(char) * ft_strlen(line) - 2);
		filename = ft_strcpy(filename, line);
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			write(1, PERMERROR, 34);
		ft_nmprint(fd);
	}
}

int main ()
{
	char *line;

	while (1)
	{
		write(1, PROMPT, 3);
		get_next_line(0, &line);
		if (ft_strncmp(line, "nm", 2) == 0)
			ft_nm(line);
	//	else if (ft_strncmp(line, "otool", 5) == 0)
		//	ft_otool(line);
		else
			write(1, ERROR2, 34);
	}
	return (0);
}
