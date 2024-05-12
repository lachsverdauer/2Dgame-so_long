/*The memset() function sets the first count bytes of dest to the value c.
The value of c is converted to an unsigned character. Return Value. The
memset() function returns a pointer to dest.*/

#include "libft.h"

void	*ft_memset(void *str, int value, size_t n)
{
	unsigned char	*c;
	size_t			i;

	c = str;
	i = 0;
	while (i < n)
	{
		*c = (unsigned char) value;
		c++;
		i++;
	}
	return (str);
}
