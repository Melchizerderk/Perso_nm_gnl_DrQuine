/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 11:24:08 by bcrespin          #+#    #+#             */
/*   Updated: 2016/01/24 18:09:19 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char *to_save(char *buf, char **s_str)
{
	int i;
	char *tmp;
	char *tmp2;
	
	i = 1;
	tmp2 = buf;
	while (i < BUF_SIZE)
	{
		if (*tmp2 == '\n')
		{
			if (i < BUF_SIZE)
			{
				*s_str = malloc(sizeof(char) * ((BUF_SIZE - (i - 1))));
				*s_str = ft_strncpy(*s_str, tmp2 + 1, BUF_SIZE - (i - 1));
				break;
			}
		}
		else if (*tmp2 == 0)
			break;
		i++;
		tmp2++;
	}
	i--;
	tmp2--;
	tmp = malloc(sizeof(char) * (i));
	tmp = ft_strncpy(tmp, buf, i);
	return (tmp);
}

int gnl(int fd, char **str)
{
	static char *s_str;
	char *buf;
	char *t_str;
	
	buf = malloc(sizeof(char) * BUF_SIZE);
	if (s_str)
	{
		if (BUF_SIZE > ft_strlen(s_str))
		{
			t_str = malloc(sizeof(char) * ft_strlen(s_str));
			t_str = ft_strcpy(t_str, s_str);
			printf("t_str : %s\n", t_str);
			read(fd, buf, BUF_SIZE);
			char *truc = to_save(buf, &s_str);
			/*le cas pile chiant, il y a un truc en sauvegarde mais la position du saut de ligne fait que c'est un cas particulier*/
			printf("%s\n", truc);
			printf("s_str3 : %s\n", s_str);
			*str = ft_strjoin(t_str, truc);
			printf("str : %s\n", *str);
			free(t_str);
		}	
		else if (BUF_SIZE < ft_strlen(s_str))
		{
			*str = ft_strncpy(*str, s_str, BUF_SIZE);
			s_str = ft_strsub(s_str, 0, BUF_SIZE);
		}
		else
		{
			*str = s_str;
			s_str = NULL;
		}
	}
	else
	{
		read(fd, buf, BUF_SIZE);
		*str = to_save(buf, &s_str);
	}
	free(buf);
	return (0);
}


int main (int ac, char **av)
{
	int fd;
	char *string;
	int i;
	fd = open(av[1], O_RDONLY);
	for (i = 0; i < 6; i++)
	{
		gnl(fd, &string);
		printf("string : %s\n", string);
	}
	return 0;
}
