/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:06:44 by marvin            #+#    #+#             */
/*   Updated: 2026/02/15 08:08:13 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 10

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	get_buffer(t_list **lst, int fd);
int		check_new_line(t_list *lst);
int		add_to_list(t_list **lst, char *buffer);
char	*ft_get_line(t_list *lst);
t_list	*ft_clean_list(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
#endif