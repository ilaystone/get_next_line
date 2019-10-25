/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 01:10:36 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/25 09:47:08 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		has_char(char *str, int c)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

/*
**	this function gets new line set it to postiing FD;
**	so it can rememcer last the pos of the cursor
**	and call multiple files read
**	TODO : make it analyse binary files
*/

int		get_next_line(int fd, char **line)
{
	static char		*reads[BUFFER_SIZE];
	int				c;
	char			*tmp;
	char			*str;

	str = ft_newstr(BUFFER_SIZE + 1);
	while ((c = read(fd, str, BUFFER_SIZE)) > 0)
	{
		str[c] = '\0';
		if (reads[fd] == NULL)
			reads[fd] = ft_newstr(1);
		tmp = ft_strjoin(reads[fd], str);
		reads[fd] = tmp;
		if (has_char(str, '\n'))
			break ;
	}
	if (c < 0)
		return (-1);
	else if (c == 0 && (reads[fd] == NULL || reads[fd][0] == '\0'))
		return (0);
	return (set_line(reads, line, fd));
}

/*
**	gets char by char from reads until '\n' and remove them
**	from reads leaving only the chars exlpicitly after '\n'
*/

int		set_line(char **reads, char **line, int fd)
{
	char	*res;
	int		len;

	res = malloc(MAX_LENGTH);
	len = 0;
	while (reads[fd][len] != '\n' && reads[fd][len] != '\0')
	{
		res[len] = reads[fd][len];
		len++;
	}
	res[len] = '\0';
	*line = ft_strdup(res);
	free(res);
	reads[fd] = ft_strdup(reads[fd] + len + 1);
	return (1);
}
