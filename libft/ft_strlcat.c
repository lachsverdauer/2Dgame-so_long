/*The strlcat() function appends the null-terminated string src to the end of
dst (but no more than size characters will be in the destination).*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (n < dlen || n == 0)
		return (slen + n);
	if (!dest)
		return (slen);
	while (src[i] && (dlen + i) < n -1)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = 0;
	return (slen + dlen);
}
