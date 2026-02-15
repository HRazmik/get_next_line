/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:06:57 by marvin            #+#    #+#             */
/*   Updated: 2026/02/15 07:42:05 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (!src)
		return (NULL);
	size = 0;
	while (src[size])
		size++;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*strlen_until_nl(t_list *lst)
{
	size_t	len;
	t_list	*tmp;
	char	*str;
	char	*s;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		s = tmp->str;
		while (*s && *s != '\n')
		{
			len++;
			s++;
		}
		if (*s == '\n')
			break ;
		tmp = tmp->next;
	}
	if (len == 0)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_get_line(t_list *lst)
{
	size_t	i;
	t_list	*tmp;
	char	*line;
	char	*dst;

	tmp = lst;
	i = 0;
	line = strlen_until_nl(lst);
	dst = line;
	while (tmp)
	{
		i = 0;
		while (tmp->str[i])
		{
			*dst++ = tmp->str[i];
			if (tmp->str[i] == '\n')
				break ;
			i++;
		}
		if (ft_strchr(tmp->str, '\n'))
			break ;
		tmp = tmp->next;
	}
	*dst = '\0';
	return (line);
}
