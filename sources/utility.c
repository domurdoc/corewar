#include "corewar.h"

void	nbr_recursion(char *s, uint32_t *i, uint32_t n, uint8_t base)
{
	static char	*range = "0123456789abcdef";

	if (n / base > 0)
		nbr_recursion(s, i, n / base, base);
	s[(*i)++] = range[n % base];
}

int		is_number(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}
