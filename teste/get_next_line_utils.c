#include "get_next_line.h"

char	*gnl_strchr(const char *str, char chr)
{
	if (!str)
		return (0);
	while (*str)
		if (*str++ == chr)
			return ((char *)(str - 1));
	return (0);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		len1;
	int		len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		while (*(s1 + len1))
			len1 ++;
	if (s2)
		while (*(s2 + len2))
			len2 ++;
	newstr = malloc(len1 + len2 + 1);
	if (!newstr)
		return (0);
	len1 = 0;
	if (s1)
		while (*s1)
			*(newstr + len1++) = *s1++;
	if (s2)
		while (*s2)
			*(newstr + len1++) = *s2++;
	*(newstr + len1) = '\0';
	return (newstr);
}

void	*gnl_calloc(size_t count, size_t size)
{
	size_t	total;
	size_t	i;
	void	*ptr;

	total = (count * size);
	if ((total < count) || (total < size))
		return (0);
	ptr = malloc(total);
	i = 0;
	if (ptr)
		while(i < total)
			*(char *)(ptr + i++) = 0;
	return (ptr);
}
