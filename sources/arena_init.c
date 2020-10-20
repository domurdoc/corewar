#include "corewar.h"

void	arena_init(void)
{
	uint8_t		i;
	t_proc		*proc;
	t_player	*player;

	i = 0;
	while (i < g_vm->n_players)
	{
		if (!(proc = proc_add()))
			exit_(ERR_SYS, NULL);
		proc_zer(proc);
		player = &g_vm->players[i];
		*(uint32_t*)proc->reg[0] = -(i + 1);
		proc->pc_adv = i * (MEM_SIZE / g_vm->n_players);
		proc->pc = proc->pc_adv;
		ft_memmove(g_vm->mem + proc->pc, player->prog_code, player->prog_size);
		g_vm->id = i + 1;
		i++;
	}
}
