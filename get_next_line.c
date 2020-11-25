/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:03:56 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/11/24 18:19:40 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*leftover(char **left, char **line)
{
	char	*pointer;

	pointer = NULL;
	if (*left)
	{
		if ((pointer = ft_strchr(*left, '\n')))
		{
			*pointer = '\0';
			*line = ft_strdup(*left);
			ft_strcpy(pointer + 1, *left);
		}
		else
		{
			*line = ft_strdup(*left);
			free(*left);
			*left = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (pointer);
}

int		ret_value(int bytes, char **pointer)
{
	if (bytes == -1)
		return (-1);
	if (*pointer)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			bytes;
	char		*buf;
	char		*pointer;
	static char	*left;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line ||
		!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	pointer = leftover(&left, line);
	while (!pointer && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if ((pointer = ft_strchr(buf, '\n')))
		{
			*pointer = '\0';
			left = ft_strdup(pointer + 1);
		}
		temp = *line;
		*line = ft_strjoin(*line, buf);
		free(temp);
	}
	free(buf);
	return ((ret_value(bytes, &pointer)));
}
