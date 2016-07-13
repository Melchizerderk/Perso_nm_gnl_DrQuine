#include "get_next_line.h"

char *ft_keepreading(const int fd, int *i)
{
	char *temp;
	char *buf;

	temp = malloc(sizeof(char) * BUFF_SIZE);
	buf = malloc(sizeof(char) * BUFF_SIZE);
	read(fd, buf, BUFF_SIZE);
	*i = ft_findchar(buf, '\n');
	while (*i == -1)
	{
		read(fd, temp, BUFF_SIZE);
		buf = ft_strdup(ft_strjoin(buf, temp));
		*i = ft_findchar(buf, '\n');
	}
	free(temp);
	printf("%d\n", *i);
	return (buf);
}

char *ft_tosaveornot(char **buf, int i, char *savedread)
{
	int d;
	char **tab;
	
	if (i == ft_strlen(*buf))
	{
		*buf = ft_strsub(*buf, 0, ft_strlen(*buf) - 1); /*pour enlever le backslash n*/
		return (NULL);
	}
	if (i <	ft_strlen(*buf))
	{
		printf("OH FDP\n");
	/*	tab = ft_strsplit(*buf, '\n');
		while(tab[i] != '\0')
		{
			printf("%s\n", tab[i]);
			i++;
		}*/
		savedread = ft_strdup(*buf);
	/*	d = ft_strlen(savedread) - (BUFF_SIZE - i);
		printf("%d\n", d);*/
	/*	if (d < 0)
		{*/
			savedread = ft_strsub(savedread, i, ft_strlen(savedread));
			*buf = ft_strsub(*buf, 0, i);
	//		printf("ICI SOUCI %d : %s : %s\n",i, *buf, savedread);
	/*	}
		else
		{
			printf("ICI FDP\n");
			savedread = ft_strsub(savedread, \
			ft_strlen(savedread) - (BUFF_SIZE - i), BUFF_SIZE - i);
			printf("%s : %s\n", *buf, savedread);
			*buf = ft_strsub(*buf, 0, ft_strlen(*buf) - (BUFF_SIZE - i - 1));
		}*/
		return (savedread);
	}
}

char *ft_read(const int fd, char **savedread, int readstatus)
{
	char	*buf;
	int	i;
	int d;

	if (readstatus != -1)
	{
		if (readstatus == 0)
		{
			buf = ft_strdup(ft_keepreading(fd, &i));
			*savedread = ft_tosaveornot(&buf, i, *savedread);
			return (buf);
		}
		if (readstatus == 1)
		{
			i = ft_findchar(*savedread, '\n');
			if (i == -1)
			{
				buf = ft_strdup(ft_keepreading(fd, &i));
				*savedread = ft_tosaveornot(&buf, i, *savedread);
				return (buf);
			}
			else
			{
				buf = ft_strdup(*savedread);
				buf = ft_strsub(buf, 0, i - 1);
				*savedread = ft_strsub(*savedread, i, ft_strlen(*savedread));
				return (buf);
			}
		}
	}
}

int get_next_line(const int fd, char **line)
{
	static char *savedread;
	int readstatus;	
	
	if (!savedread)
		readstatus = 0;
	else if (ft_strlen(savedread) < BUFF_SIZE)
	{
		printf("Ce qui a ete saved precedemment : %s\n", savedread);
		readstatus = 1;
	}
	*line =	ft_read(fd, &savedread, readstatus);
return (0);
}
