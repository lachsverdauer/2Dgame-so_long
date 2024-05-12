/*The split() function can be used to split a given string or a line by
specifying one of the substrings of the given string as the delimiter. The
string before and after the substring specified as a delimiter is returned
as the output.*/

#include "libft.h"

static int	ft_cnum(char *s, char c)
{
	int	is;

	is = 0;
	while (s[is])
	{
		if (s[is] == c || s[is] == '\0')
			return (is);
		is++;
	}
	return (is);
}

static int	ft_num(char *s, char c)
{
	int	is;
	int	j;
	int	x;

	is = 0;
	j = 0;
	while (s[is])
	{
		x = 0;
		while (s[is] == c && s[is])
			is++;
		while (s[is] != c && s[is])
		{
			is++;
			x = 1;
		}
		if (x == 1)
			j++;
	}
	return (j);
}

static char	**ft_malloc(char const *s, char c)
{
	char	**ss;
	int		is;
	int		j;

	ss = malloc((ft_num((char *)s, c) + 1) * sizeof(char *));
	if (ss == NULL)
		return (NULL);
	is = -1;
	j = 0;
	while (s[++is])
	{
		if (s[is] != c)
		{
			ss[j] = malloc((ft_cnum((char *)s + is, c) + 1)
					* sizeof(char));
			if (ss[j++] == NULL)
				return (NULL);
			while (s[is] != c && s[is] != '\0')
				is++;
		}
		if (s[is] == '\0')
			break ;
	}
	ss[j] = 0;
	return (ss);
}

static char	**ft_allwork(char const *s, char c, size_t is, size_t j)
{
	char	**ss;
	size_t	i;

	ss = ft_malloc(s, c);
	if (!ss)
		return (NULL);
	while (s[++is])
	{
		if (s[is] != c)
		{
			i = 0;
			while (s[is] != c && s[is] != '\0')
			{
				ss[j][i++] = s[is++];
				if (s[is] == c || s[is] == '\0')
					ss[j][i] = '\0';
			}
			j++;
		}
		if (s[is] == '\0')
			break ;
	}
	return (ss);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	size_t	is;
	size_t	j;

	is = -1;
	j = 0;
	if (!s)
		return (NULL);
	ss = ft_allwork(s, c, is, j);
	if (!ss)
		return (NULL);
	return (ss);
}
