/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 01:21:01 by ikhadem           #+#    #+#             */
/*   Updated: 2019/10/31 13:07:25 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *str)
{
	char		*res;

	if (!(res = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	return ((char *)ft_memcpy(res, str, ft_strlen(str) + 1));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*res;

	if (!(res = (char *)malloc(strlen(s1) + strlen(s2) + 1)))
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_memcpy(res + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (res);
}

char	*ft_newstr(size_t len)
{
	char	*res;

	if (!(res = (char *)malloc(len)))
		return (NULL);
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!len || dest == src)
		return (dest);
	d = (char *)dest;
	s = (const char *)src;
	while (len--)
		*d++ = *s++;
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t		size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}
