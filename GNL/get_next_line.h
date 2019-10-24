/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:36:57 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/24 14:52:45 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <libc.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 1000000
# define MAX_FD 10240


int		has_char(char *str, int c);
int		get_next_line(int fd, char **line);
int		set_line(char **reads, char **line, int fd, int c);
char	*ft_newstr(size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t len);

#endif
