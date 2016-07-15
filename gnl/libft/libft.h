/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:28:34 by bcrespin          #+#    #+#             */
/*   Updated: 2014/05/16 19:00:43 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# define INT_MIN (-INT_MAX - 1)
# define INT_MAX 2147483647
/*# define BUFF_SIZE 4096*/

int					ft_atoi		(const char *str);
char				*ft_itoa	(int	n);
int					ft_tolower	(int	c);
int					ft_toupper	(int	c);
void				*ft_bzero	(void	*s, size_t n);
void				*ft_realloc	(void *ptr, size_t size);

/*
**		IS
*/

int					ft_isalpha	(int	c);
int					ft_isdigit	(int	c);
int					ft_isalnum	(int	c);
int					ft_isascii	(int	c);
int					ft_isprint	(int	c);

/*
**		STR
*/

size_t				ft_strlen	(const char	*s);
char				*ft_strdup	(const char	*s1);
char				*ft_strcpy	(char	*s1, const char *s2);
char				*ft_strncpy	(char	*s1, const char *s2, int n);
char				*ft_strcat	(char	*s1, const char *s2);
char				*ft_strncat	(char	*s1, const char *s2, size_t n);
char				*ft_strstr	(const char	*s1, const char *s2);
char				*ft_strnstr	(const char *s1, const char *s2, size_t n);
int					ft_strcmp	(const char *s1, const char *s2);
int					ft_strncmp	(const char *s1, const char *s2, size_t n);
char				*ft_strchr	(const char*s, int c);
char				*ft_strrchr	(const char *s, int c);
size_t				ft_strlcat	(char *dst, const char *src, size_t size);
char				*ft_strdup	(const char *s1);
char				*ft_strchr	(const char*s, int c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
int					ft_strcnttoc(char *s, char c);
char				**ft_strsplit(char const *s, char c);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strndup(const char *s1, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);

typedef struct		s_strsplit
{
	int		i;
	int		e;
	char	**tabtemp;
	char	**tab;
}					t_split;

/*
**		MEM
*/

void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *b, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**		PUT
*/

int					ft_putchar(char c);
void				ft_putendl(char *s);
int					ft_putstr	(const char *s);
int					ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
int					ft_putstr_fd(char const *s, int fd);
int					ft_putnbr(int n);
int					ft_putnbr_fd(int n, int fd);
int					ft_putnbru(unsigned int n, int b);
int					ft_putnbru_fd(unsigned int n, int b, int fd);
int					ft_putpoint(long unsigned int n);
int					ft_putpoint_fd(long unsigned int n, int fd);

/*
** liste chainee
*/

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list				*ladd_front(t_list *lst, void *value);
t_list				*ladd_rear(t_list *lst, void *value);
t_list				*lnew(void *value);

/*
**	PRINT
*/

int					ft_printf(const char *s, ...);
int					ft_dprintf(int fd, const char *s, ...);
int					ft_sizei(char *s);

int					ft_findchar(char *str, char c);
/*int					get_next_line(int fd, char **line);*/
#endif
