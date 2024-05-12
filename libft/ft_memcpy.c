/*memcpy copies the number of bytes specified by n from one area of memory
( from ) to another ( to ). All bytes, including any null characters,
are copied.*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	i = 0;
	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*d = *s;
		s++;
		d++;
		i++;
	}
	return (dest);
}
