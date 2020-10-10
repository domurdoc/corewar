#include "corewar.h"

void	dump(void)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		n = 64 * i;
		ft_printf("%#06x : ", n);
		while (++j < 64)
		{
			ft_printf("%02x ", g_os.mem[n + j]);
		}
		ft_printf("\n");
	}
}
