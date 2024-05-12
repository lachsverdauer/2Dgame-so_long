/*The memcmp() built-in function compares the first count bytes of str1 and
str2. The relation is determined by the sign of the difference between the
values of the leftmost first pair of bytes that differ.*/

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *) str1;
	s2 = (unsigned char *) str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}
