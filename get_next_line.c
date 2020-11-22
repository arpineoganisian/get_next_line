/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:03:56 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/11/22 21:51:04 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 16

char	*leftover(char *left, char **line)
{
	char	*n;

	n = NULL;
	if (left)
	{
		if ((n = ft_strchr(left, '\n')))
		{
			*n = '\0';
			*line = ft_strdup(left);
			ft_strcpy(n + 1, left);
		}
		else
		{
			*line = ft_strdup(left);
			*left = '\0';
		}
	}
	else
		*line = ft_strdup("");
	return (n);
}

int		get_next_line(int fd, char **line)
{
	int			bytes;
	char		*buf;
	char		*n;
	static char	*left;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 ||
		!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	n = leftover(left, line);
	while (!n && (bytes = read(fd, buf, BUFFER_SIZE)))
	{	
		if (bytes == -1)
		{	
			free(buf);
			return (-1);
		}
		buf[bytes] = '\0';
		if ((n = ft_strchr(buf, '\n')))
		{
			*n = '\0';
			left = ft_strdup(n + 1);
		}
		temp = *line;
		*line = ft_strjoin(*line, buf);
		free(temp);
		temp = NULL;
	}
	free(buf);
	return (n ? 1 : 0);
}

int main()
{
    int     fd;
    char    *line;
    int     i;
	int		count;

	count = 1;

    fd = open("lorem_ipsum", O_RDONLY);

    while ((i = get_next_line(fd, &line)))
    {
        printf("/%d/ i is %d/ =%s=\n", count++, i, line);
        free(line);
    }
    printf("/%d/ i is %d/ =%s=\n", count, i, line);
    free(line);
    close(fd);
//	while (1)
//      ;
}
