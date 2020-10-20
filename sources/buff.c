#include "corewar.h"

void	buff_flush(void)
{
	if (write(STDOUT_FILENO, g_vm->buff.s, g_vm->buff.i) < 0)
		exit_(ERR_SYS, NULL);
	g_vm->buff.i = 0;
}

void	buff_str(char *src)
{
	while (*src)
	{
		if (g_vm->buff.i == BUFF_SIZE)
			buff_flush();
		g_vm->buff.s[g_vm->buff.i++] = *src++;
		g_vm->buff.n++;
	}
}

void	buff_number(int32_t n, uint8_t base)
{
	char		temp[16];
	uint32_t	i;

	i = 0;
	if (n < 0)
	{
		temp[i++] = '-';
		n = -n;
	}
	nbr_recursion(temp, &i, (uint32_t)n, base);
	temp[i] = '\0';
	buff_str(temp);
}
