/*Concatenates all of the elements of a string array into a single scalar
string.*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy((void *)new, (const void *)s1, ft_strlen((char *)s1));
	ft_memmove((void *)(new + ft_strlen((char *)s1)),
		(const void *)s2, ft_strlen((char *)s2));
	new[len] = '\0';
	return (new);
}
