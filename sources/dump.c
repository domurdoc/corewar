#include "corewar.h"

void	dump(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%04x : ", i);
		j = -1;
		while (++j < 32)
		{
			ft_printf("%02x ", g_os.mem[i + j]);
		}
		i += 32;
		ft_printf("\n");
	}
}
