/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:28:52 by thfirmin          #+#    #+#             */
/*   Updated: 2022/07/15 21:36:40 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(int count, int size)
{
	char	*ptr;
	size_t	len;

	len = 0;
	ptr = malloc (count * size);
	if (!ptr)
		return (0);
	while (len < (unsigned int)(count * size))
		*(ptr + len++) = 0;
	return ((void *) ptr);
}

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
