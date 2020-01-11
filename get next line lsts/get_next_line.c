#include "get_next_line.h"
#include <stdio.h>

typedef struct s_str
{
	char *content;
	struct s_str *next;
} t_str;

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int size = ft_strlen(str);
	int i = 0;
	char *res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

t_str *ft_lstnew(char *content)
{
	t_str *res;

	res = (t_str *)malloc(sizeof(t_str));
	if (!res)
		return (NULL);
	res->content = ft_strdup(content);
	res->next = NULL;
	return (res);
}

int ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void print_list(t_str *list)
{
	while (list)
	{
		printf("%s", list->content);
		list = list->next;
	}
}

void ft_lstaddback(t_str **lst, char *n)
{
	t_str *last;
	t_str *new;

	new = ft_lstnew(n);
	last = *lst;
	if (last == NULL)
		*lst = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

int str_length(t_str *lst)
{
	int i = 0;
	int total = 0;

	while (lst)
	{
		i = 0;
		while (lst->content[i] != '\0' && lst->content[i] != '\n')
			i++;
		total += i;
		if (lst->content[i] == '\n')
			return (total);
		else
			lst = lst->next;
	}
	return (total);
}

void free_node(t_str **data)
{
	t_str *tmp;

	tmp = *data;
	if (tmp)
	{
		*data = (*data)->next;
		free(tmp->content);
		free(tmp);
	}
}

int fill_line(t_str **data, char **line)
{
	char *res;
	char *h;
	int size;
	int i = 0;
	int j = 0;

	size = str_length(*data);
	res = (char *)malloc(size + 1);
	res[size] = '\0';
	while (*data)
	{
		i = 0;
		while ((*data)->content[i] != '\0' && (*data)->content[i] != '\n')
			res[j++] = (*data)->content[i++];
		if ((*data)->content[i] == '\0')
			free_node(data);
		else
		{
			h = (*data)->content;
			(*data)->content = ft_strdup(h + i + 1);
			free(h);
			*line = res;
			return (1);
		}
	}
	*line = res;
	return (0);
}

int lst_strchr(t_str *lst, char c)
{
	while (lst)
	{
		if (ft_strchr(lst->content, c) == 1)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int get_next_line(char **line)
{
	static t_str *data = NULL;
	int c = 0;
	char str[129];
	if (lst_strchr(data, '\n') != 1)
	{
		while ((c = read(0, str, 128)))
		{
			str[c] = '\0';
			ft_lstaddback(&data, str);
			if (ft_strchr(str, '\n') == 1)
				break;
		}
	}
	if (c == -1 || !line)
		return (-1);
	if (c == 0 && data == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (fill_line(&data, line));
}
