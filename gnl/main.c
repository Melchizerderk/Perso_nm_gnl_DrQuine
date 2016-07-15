#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line = NULL;
	int fd;
	int i = -2;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (i != 0 && i != -1)
		{
			printf("T'EST CON\n");
			printf("%d\n", i = get_next_line(fd, &line));
			if (i != 0)
				printf("Ce que je recupere avant de relancer gnl : %s\n", line);
		}
	}
	close(fd);
return(0);
}
