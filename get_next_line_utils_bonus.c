/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:28:52 by thfirmin          #+#    #+#             */
/*   Updated: 2022/07/23 05:09:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (unsigned char) c)
			return (str);
		str ++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str)
		while (*(str + len))
			len ++;
	return (len);
}

t_list	*backup_line(int fd, t_list *list)
{
	while (list)
	{
		if (list -> f_fd == fd)
			return (list);
		list = list -> newfile;
	}
	return (0);
}

t_list	*addnew_list(int fd, t_list *list)
{
	t_list	*new ;

	new = (t_list *) malloc (sizeof(t_list));
	if (!new)
		return (0);
	new -> f_fd = fd;
	new -> f_str = malloc(1);
	*(new -> f_str) = '\0';
	new -> newfile = 0;
	if (!list)
		list = new;
	else
	{
		while (list -> newfile)
			list = list -> newfile;
		list -> newfile = new;
	}
	return (new);
}

t_list	*ft_free(t_list *list, t_list *node)
{
	t_list	*aux;

	aux = list;
	if (node == list)
		list = node -> newfile;
	else
	{
		while ((aux -> newfile) != node)
			aux = aux -> newfile;
		aux -> newfile = node -> newfile;
	}
	free (node);
	return (list);
}
