#include "get_next_line.h"

static char	*gnl_cutendl(char *f_line);

static char	*gnl_getendl(char *f_line);

static void	gnl_takendl(int fd, static char *line);

char	*get_next_line(int fd)
{
	static char	*b_line;
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		free (b_line);
		return (0);
	}
	line = 0;
	gnl_takendl(fd, b_line);
	if (b_line)
	{
		line = gnl_getendl(b_line);
		b_line = gnl_cutendl(b_line);
	}
	return (line);
}

static void	gnl_takendl(int fd, static char *line)
{
	char	*buffer;
	char	*aux;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free (line);
		return(0);
	}
	while (!gnl_strchr(line, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes)
			break;
		*(buffer + bytes) = '\0';
		aux = gnl_strjoin(line, buffer);
		free (line);
		line = aux;
	}
	free (buffer);
}

static char	*gnl_getendl(char *f_line)
{
	char	*newline;
	int		len;
	int		i ;

	len = 0;
	i = 0;
	while (*(f_line + len) && *(f_line + len) != '\n')
		len ++;
	if (*(f_line + len) == '\n')
		len ++;
	newline = malloc(len + 1);
	if (!newline)
		return (0);
	while (len--)
		*(newline + i++) = *f_line++;
	*(newline + i) = '\0';
	return (newline);
}

static char	*gnl_cutendl(char *f_line)
{
	int		i;
	int		len;
	char	*rest;

	i = 0;
	len = 0;
	while (*(f_line + i) && *(f_line + i) != '\n')
		i ++;
	if (!*(f_line + i++))
	{
		free (f_line);
		return (0);
	}
	while (*(f_line + i + len))
		len ++;
	rest = malloc(len + 1);
	len = -1;
	if (rest)
		while (*(f_line + i + ++len))
			*(rest + len) = *(f_line + i + len);
	free (f_line);
	return (rest);
}
