/*The itoa() function coverts the integer n into a character string. The
string is placed in the buffer passed, which must be large enough to hold the
output.*/

#include "libft.h"

static size_t	ft_counter(size_t	nbr)
{
	size_t	i;

	i = 0;
	if (!nbr)
		i++;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_putinstr(int minus, size_t nbr, int i)
{
	char	*p;

	p = malloc(sizeof(char) * i);
	if (!p)
		return (NULL);
	if (minus)
		p[0] = '-';
	p[--i] = '\0';
	if (!nbr && i--)
		p[i] = '0' + 0;
	while (nbr > 0 && i--)
	{
		p[i] = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	long long int	nbr;
	int				minus;
	int				i;
	char			*p;

	if (!n && n != 0)
		return (0);
	nbr = n;
	i = 0;
	minus = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
		minus++;
	}
	i = i + ft_counter(nbr);
	p = ft_putinstr(minus, nbr, i);
	return (p);
}
