/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:36:46 by bcrespin          #+#    #+#             */
/*   Updated: 2014/11/11 19:38:12 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	word_count(const char *s, int c)
{
	unsigned int	wc;

	wc = 0;
	while (*s)
	{
		while (*s == (char)c)
			++s;
		if (*s == '\0')
			break ;
		while (*s != (char)c && *s != '\0')
			++s;
		wc += 1;
	}
	return (wc);
}

char				**ft_strsplit(const char *s, int c)
{
	unsigned int	wc;
	char			**tab;
	unsigned int	i;
	char			*word;

	wc = word_count(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	i = 0;
	while (i < wc)
	{
		while (*s == (char)c)
			++s;
		word = (char *)s;
		while (*s != (char)c && *s != '\0')
			++s;
		tab[i++] = ft_strsub(word, 0, s - word);
	}
	tab[i] = NULL;
	return (tab);
}
