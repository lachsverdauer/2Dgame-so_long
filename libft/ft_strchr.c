/*The strchr() function finds the first occurrence of a character in a
string. The character c can be the null character (\0); the ending null
character of string is included in the search. The strchr() function
operates on null-ended strings.*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (c > 127)
		c = c - 128;
	while (*str)
	{
		if (c == *str)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
