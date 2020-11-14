/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:59:15 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/11/13 18:40:03 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXR_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
int get_next_line(int fd, char **line);
#endif
