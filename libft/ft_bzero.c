/*The bzero() function places n zero-valued bytes in the area pointed to by
str.*/

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*c;
	size_t			i;

	c = str;
	i = 0;
	while (i < n)
	{
		*c = '\0';
		i++;
		c++;
	}
}
