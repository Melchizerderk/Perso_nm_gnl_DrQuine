#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line = NULL;
	int fd;
	int i = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (i <= 4)
		{
			get_next_line(fd, &line);
			printf("Ce que je recupere avant de relancer gnl : %s\n", line);
			i++;
		}
	}
return(0);
}
