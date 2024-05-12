#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen((char *)src) + 1);
	if (!dest)
		return (NULL);
	dest = ft_strcpy((char *)src, dest);
	return (dest);
}

char	*ft_strcpy(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
