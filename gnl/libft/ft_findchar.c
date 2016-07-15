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
