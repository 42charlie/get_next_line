/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsadik <ahsadik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:12:28 by ahsadik           #+#    #+#             */
/*   Updated: 2023/12/14 21:33:26 by ahsadik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*buff_join(char *content, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(content, buffer);
	free(content);
	return (tmp);
}

static	char	*get_content(int fd, char *content)
{
	char	*buffer;
	int		byts;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byts = 1;
	while (byts > 0)
	{
		byts = read(fd, buffer, BUFFER_SIZE);
		buffer[byts] = '\0';
		content = buff_join(content, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (content);
}

static	char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	if (buffer[i] == '\n')
		i++;
	line[i] = '\0';
	return (line);
}

static	char	*get_next(char *buffer, char *line)
{
	char	*new_buffer;
	int		line_len;
	int		rest;
	int		i;

	line_len = ft_strlen(line);
	rest = ft_strlen(buffer) - line_len;
	if (rest == 0)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(rest + 1, sizeof(char));
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (i < rest)
		new_buffer[i++] = buffer[line_len++];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = get_content(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = get_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = get_next(buffer, line);
	return (line);
}
