#include "get_next_line.h"

int ft_findchar(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
return (-1);
}

char *ft_keepreading(const int fd, int *i, char *savedread)
{
	char *buf;
	
	buf = malloc(sizeof(char) * BUFF_SIZE);
	while (*i == -1)
	{
		read(fd, buf, BUFF_SIZE);
		*i = ft_findchar(buf, '\n');
		savedread = ft_strjoin(savedread, buf);
		printf("dans keepreading %d : %s\n", *i, savedread);
	}
	free(buf);
	return  (savedread);
}

char *ft_tosaveornot(char **buf, int i, char *savedread)
{
	if (i == BUFF_SIZE)
	{
		printf("ICI\n");
		*buf = ft_strsub(*buf, 0, ft_strlen(*buf) - 1); /*pour enlever le backslash n*/
		return (NULL);
	}
	if (i < BUFF_SIZE && i != -1)
	{
		printf("HALLO\n");
		savedread = ft_strdup(*buf);
		printf("dans tosaveornot 1 %d : %s : %s\n", i, *buf, savedread);
		savedread = ft_strsub(savedread, ft_strlen(savedread) - (BUFF_SIZE - i), BUFF_SIZE - i);
		printf("dans tosaveornot 3 %d : %s : %s\n", i, *buf, savedread);
		*buf = ft_strsub(*buf, 0, ft_strlen(*buf) - (BUFF_SIZE - i - 1));
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
			buf = malloc(sizeof(int) * BUFF_SIZE);
			read(fd, buf, BUFF_SIZE);
			i = ft_findchar(buf, '\n');
			printf("%d\n", i);
			if (i == -1)
			{
				*savedread = ft_strdup(buf);
				buf = ft_keepreading(fd, &i, *savedread);
			}
			*savedread = ft_tosaveornot(&buf, i, *savedread);
			return (buf);
			
		}
		if (readstatus == 1)
		{
			printf("READSTATUS 1 %s : %s\n", buf, *savedread);
			i = ft_findchar(*savedread, '\n');
			if (i == -1)
			{
				buf = ft_strdup(ft_keepreading(fd, &i, *savedread));
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
