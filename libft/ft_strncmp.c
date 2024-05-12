/*strncmp compares two character strings ( str1 and str2 ) using the standard
EBCDIC collating sequence. The return value has the same relationship to 0 as
str1 has to str2.*/

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
