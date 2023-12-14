/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsadik <ahsadik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:14:14 by ahsadik           #+#    #+#             */
/*   Updated: 2023/12/13 19:13:39 by ahsadik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *source );
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *str, int c);
void	*ft_calloc( size_t count, size_t size );
char	*ft_strjoin(char const *s1, char const *s2);

#endif