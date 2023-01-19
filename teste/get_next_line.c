#include "get_next_line.h"

static char	*gnl_cutendl(char *f_line);

static char	*gnl_getendl(char *f_line);

static void	gnl_readendl(int fd, char **line);

char	*get_next_line(int fd)
{
	static char	*b_line;
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		free (b_line);
		b_line = 0;
		return (0);
	}
	line = 0;
	gnl_readendl(fd, &b_line);
	line = gnl_getendl(b_line);
	b_line = gnl_cutendl(b_line);
	return (line);
}

static void	gnl_readendl(int fd, char **line)
{
	char	*buffer;
	char	*aux;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free (*line);
		return ;
	}
	if (!*line)
		*line = 0;
	while (!gnl_strchr(*line, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes)
			break;
		*(buffer + bytes) = '\0';
		aux = gnl_strjoin(*line, buffer);
		free (*line);
		*line = aux;
	}
	free (buffer);
}

static char	*gnl_getendl(char *f_line)
{
	char	*newline;
	int		len;
	int		i ;

	if (!f_line)
		return (0);
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
	char	*rest;
	char	*ptr;

	if (!f_line)
		return (0);
	rest = 0;
	ptr = f_line;
	while (*f_line && (*f_line != '\n'))
		f_line ++;
	if (*f_line == '\n')
		f_line++;
	i = 0;
	while (*(f_line + i))
		i ++;
	rest = malloc(i + 1);
	if (!rest)
		free(ptr);
	if (!rest)
		return (0);
	i = 0;
	while (*f_line)
		*(rest + i++) = *f_line++;
	free (ptr);
	return (rest);
}
