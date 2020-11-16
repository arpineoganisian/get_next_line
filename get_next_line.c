/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:03:56 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/11/16 21:21:04 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 6

int		get_next_line(int fd, char **line)
{

	int			bytes;
	char		*buf;
	char		*n;
	static char	*left;
	int			flag;

	flag = 1;
	buf = malloc(BUFFER_SIZE + 1);
	
	if (left)
		*line = ft_strdup(left);
	else
		*line = ft_strdup("");
	while ((bytes = read(fd, buf, BUFFER_SIZE)) && flag)
	{
		buf[bytes] = '\0';
//		printf("%d\n", bytes);
//		printf("\n%s\n", buf);
//		ft_strjoin(*line, buf);
		if ((n = ft_strchr(buf, '\n')))
		{
			*n = '\0';
			n++;
			left = ft_strdup(n);
			flag = 0;
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int main()
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);

	get_next_line(fd, &line);
	printf("--%s--\n", line);
	get_next_line(fd, &line);
	printf("--%s--\n", line);
}
