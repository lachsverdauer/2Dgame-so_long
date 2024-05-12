/*A string's substr() method extracts length characters from the string,
counting from the start index. If start >= str. length , an empty string is
returned. If start < 0 , the index starts counting from the end of the
string.*/

#include "libft.h"

static size_t	ft_len(size_t slen, size_t len, unsigned int start)
{
	if (start >= slen)
		len = 0;
	else if (slen - start < len)
		len = slen - start;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	len = ft_len(slen, len, start);
	subs = (char *)malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	if (start >= slen)
	{
		subs[0] = '\0';
		return (subs);
	}
	while (i < len && s[start + i] != '\0' && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
