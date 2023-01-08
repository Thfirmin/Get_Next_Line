#include "get_next_line.h"

char	*gnl_strchr(const char *str, char chr)
{
	while (str && *str)
	{
		if (*str == chr)
			return ((char *)str);
		str ++;
	}
	return (0);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		len1;
	int		len2;

	len1 = 0;
	len2 = 0;
	while (s1 && *(s1 + len1))
		len1 ++;
	while (s2 && *(s2 + len2))
		len2 ++;
	newstr = malloc(len1 + len2 + 1);
	if (!newstr)
		return (0);
	len1 = 0;
	while (s1 && *s1)
		*(newstr + len1++) = *s1++;
	while (s2 && *s2)
		*(newstr + len1++) = *s2++;
	return (newstr);
}
