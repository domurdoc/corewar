#include "corewar.h"

static void	players_init(void)
{
	uint8_t	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		g_vm->players[i].file_name = NULL;
		g_vm->players[i].prog_name[PROG_NAME_LENGTH] = '\0';
		g_vm->players[i].comment[COMMENT_LENGTH] = '\0';
		i++;
	}
}

t_vm	*g_vm;

void		vm_init(t_vm *vm)
{
	g_vm = vm;
	(void)ft_memset(g_vm->mem, 0, MEM_SIZE);
	g_vm->cycles_passed = 0;
	g_vm->ctd = CYCLE_TO_DIE;
	g_vm->cycles_to_check = CYCLE_TO_DIE;
	g_vm->cycles_to_dump = -1;
	g_vm->id = 0;
	g_vm->live_counter = 0;
	g_vm->chk_counter = 0;
	g_vm->n_players = 0;
	g_vm->p_ids = 0;
	g_vm->verb = 0;
	g_vm->dump = 0;
	g_vm->buff.i = 0;
	g_vm->buff.n = 0;
	g_vm->is_size = IS_SIZE_STD;
	players_init();
	dlst_cir_init(&g_vm->procs);
}
