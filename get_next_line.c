/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:06:54 by marvin            #+#    #+#             */
/*   Updated: 2026/02/13 09:06:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_clean_list(t_list *lst)
{
	t_list	*current;
	t_list	*temp;
	char *newline_pos;
	char *remaining_str;

	current = lst;
	while (current)
	{
		if (ft_strchr(current->str, '\n'))
		{
			newline_pos = ft_strchr(current->str, '\n');
			remaining_str = ft_strdup(newline_pos + 1);
			if (!remaining_str)
				return (NULL);
			free(current->str);
			current->str = remaining_str;
			return (lst);
		}
		else
		{
			temp = current;
			current = current->next;
			free(temp->str);
			free(temp);
		}
	}
	return (NULL);
}

int add_to_list(t_list **lst, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buffer);
		return (0);
	}
	last_node = ft_lstlast(*lst);
		if (!*lst)
		{
			*lst = new_node;
			return (1);
		}
	last_node->next = new_node;
	new_node->str = buffer;
	new_node->next = NULL;
	return (1);	
}

int check_new_line(t_list **lst)
{
	t_list *current;
	current = *lst;
	while (current)
	{
		if (ft_strchr(current->str, '\n'))
			return (1);
		current = current->next;
	}
	return (0);
}

void get_buffer(t_list **lst, int fd)
{
	int		read_bytes;
	int		flag;
	char	*buffer;

	buffer = NULL;
	flag = 1;
	while (!check_new_line(lst) && flag)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
		{
			free(buffer);
			return ;
		}
		buffer[read_bytes] = '\0';
		flag = add_to_list(lst, buffer);
	}
}

char *get_next_line(int fd)
{
	static t_list	*lst;
	char	*buffer;

	lst = NULL;
	buffer = 0;
	if ( fd < 0 || BUFFER_SIZE < 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	get_buffer(&lst, fd);
	buffer = ft_get_line(lst);
	lst = ft_clean_list(lst);
	return (buffer);
}
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}