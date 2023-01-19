#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*line;
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	do
	{
		line = get_next_line(fd);
		printf ("%s", line);
		free(line);
	} while (line);
	close (fd);
	return (0);
}
