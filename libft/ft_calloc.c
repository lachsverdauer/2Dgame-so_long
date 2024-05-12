#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	void	*arr;

	i = n * size;
	arr = (void *) malloc (i);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, i);
	return (arr);
}
