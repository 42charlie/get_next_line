/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsadik <ahsadik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:17:04 by ahsadik           #+#    #+#             */
/*   Updated: 2023/12/10 16:20:05 by ahsadik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

void	*ft_calloc( size_t count, size_t size )
{
	size_t	space;
	char	*mem;
	size_t	i;

	space = count * size;
	if (count != 0 && space / count != size)
		return (0);
	mem = malloc(space);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < space)
		mem[i++] = 0;
	return (mem);
}

int	ft_strchr(const char *str, int c)
{
	size_t	n;
	size_t	str_len;

	str_len = ft_strlen(str);
	n = 0;
	while (n <= str_len)
	{
		if (str[n] == (char)c)
			return (1);
		n++;
	}
	return (0);
}

char	*ft_strdup(const char *source)
{
	char	*mem;
	size_t	size;
	size_t	i;

	size = ft_strlen(source) + 1;
	mem = malloc(size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mem[i] = source[i];
		i++;
	}
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	int		n;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	mem = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!mem)
		return (NULL);
	n = 0;
	while (*s1)
		mem[n++] = *(s1++);
	while (*s2)
		mem[n++] = *(s2++);
	mem[n] = '\0';
	return (mem);
}
