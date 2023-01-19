#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

// Main
char	*get_next_line(int fd);

// Utils
char	*gnl_strchr(const char *str, char chr);
char	*gnl_strjoin(const char *s1, const char *s2);
void	*gnl_calloc(size_t count, size_t size);

#endif
