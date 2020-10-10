#include "corewar.h"

void	arena_init(void)
{
	uint8_t		i;
	t_proc		*proc;
	t_player	*player;

	i = 0;
	while (i < g_os.n_players)
	{
		if (!(proc = proc_add()))
			exit(EXIT_FAILURE);
		proc_zer(proc);
		player = &g_os.players[i];
		*(uint32_t*)proc->reg[0] = -(i + 1);
		proc->pc_adv = i * (MEM_SIZE / g_os.n_players);
		proc->pc = proc->pc_adv;
		ft_memmove(g_os.mem + proc->pc, player->prog_code, player->prog_size);
		g_os.id = i + 1;
		i++;
	}
}
