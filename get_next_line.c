/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:57:26 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/11/14 18:38:27 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#define BUFFER_SIZE 4

int get_next_line(int fd, char **line)
{
	static char	*ost[1024];
	char 		*buf;
	char		*tmp;
	int			bytes;

	ost = NULL;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	while ((bytes = read(fd, buf, BUFFER_SIZE)))
	{
		if ()
		buf[bytes] = '\0';
		ost = ft_strjoin(ost + buf);
	}
	return();

/*
Return value 
1 : A line has been read
0 : EOF has been reached
-1 : An error happened

External functs. read, malloc, free

Write a function which returns a line read from a
file descriptor, without the newline.
*/

//ssize_t read(int fd, void *buf, size_t count);		
}

int main()
{
	int fd;
	char *line;
	int i;
	
	line = NULL; 
	fd = open("file", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("i = %d %s\n", i, line);
		free(line);
	}
	printf("i = %d %s", i, line);
	free(line);
}
