#define BUFF_SIZE 10
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft42/libft.h"
#include <stdio.h>

int get_next_line(const int fd, char **line);
