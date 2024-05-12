/*The strrchr() function finds the last occurrence of c (converted to a char)
in string. The ending NULL character is considered part of the string.*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	while (c > 127)
		c = c - 128;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
