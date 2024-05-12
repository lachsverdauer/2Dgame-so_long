/*The atoi() function converts a character string to an integer value. The
input string is a sequence of characters that can be interpreted as a numeric
value of the specified return type. The function stops reading the input string
at the first character that it cannot recognize as part of a number. This
character can be the null character that ends the string.*/

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
