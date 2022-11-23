/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:49:21 by thfirmin          #+#    #+#             */
/*   Updated: 2022/07/23 05:08:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*list_files;
	t_list			*node;
	char			*line;

	if (!list_files)
		list_files = addnew_list(fd, list_files);
	node = backup_line(fd, list_files);
	if (!node)
		node = addnew_list(fd, list_files);
	if (read(node->f_fd, 0, 0) || BUFFER_SIZE <= 0)
	{
		free(node -> f_str);
		node -> f_str = (void *)0;
		list_files = ft_free(list_files, node);
		return (0);
	}
	node -> f_str = read_line(fd, node -> f_str);
	line = take_line(node -> f_str);
	node -> f_str = clean_buffer(node -> f_str);
	if (!node -> f_str)
		list_files = ft_free(list_files, node);
	return (line);
}

char	*read_line(int fd, char *str)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free (str);
		return (0);
	}
	while (!ft_strchr(str, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if ((!str) || ((bytes < BUFFER_SIZE) && (*str)))
			break ;
		else if ((*str == '\0') && (bytes <= 0))
		{
			free (str);
			str = (void *)0;
			break ;
		}
	}
	free(buffer);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*newstr;

	if (!s1)
		return (0);
	newstr = (void *)0;
	i = -1;
	len = (ft_strlen(s1) + ft_strlen(s2));
	newstr = malloc((len + 1) * sizeof(char));
	if (!newstr)
	{
		free (s1);
		return (0);
	}
	while (*(s1 + ++i))
		newstr[i] = s1[i];
	if (s2)
		while (*s2)
			newstr[i++] = *s2++;
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

char	*take_line(char *str)
{
	char	*line;
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\n' && str[len])
		len ++;
	if (str[len] == '\n')
		len ++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (0);
	len = 0;
	while (str[len] != '\n' && str[len])
	{
		line[len] = str[len];
		len ++;
	}
	if (str[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

char	*clean_buffer(char *buffer)
{
	size_t	len;
	char	*str;
	size_t	i;

	if (!buffer)
		return (0);
	len = 0;
	i = 0;
	while (buffer[len] != '\n' && buffer[len])
		len ++;
	if (buffer[len] == '\n')
		len ++;
	str = malloc((ft_strlen(buffer + len) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (buffer[len])
		str[i++] = buffer[len++];
	str[i] = '\0';
	free(buffer);
	return (str);
}
