#include "corewar.h"

void	dump(void)
{
	int	i;
	int	j;

	i = 0;
	buff_flush();
	while (i < MEM_SIZE)
	{
		ft_printf("0x%04x : ", i);
		j = -1;
		while (++j < g_vm->dump)
		{
			ft_printf("%02x ", g_vm->mem[i + j]);
		}
		i += g_vm->dump;
		ft_printf("\n");
	}
}
