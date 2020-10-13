#include "corewar.h"

static void	players_init(void)
{
	uint8_t	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		g_os.players[i].file_name = NULL;
		g_os.players[i].prog_name[PROG_NAME_LENGTH] = '\0';
		g_os.players[i].comment[COMMENT_LENGTH] = '\0';
		i++;
	}
}

void		vm_init(void)
{
	(void)ft_memset(g_os.mem, 0, MEM_SIZE);
	g_os.cycles_passed = 0;
	g_os.ctd = CYCLE_TO_DIE;
	g_os.cycles_to_check = CYCLE_TO_DIE;
	g_os.cycles_to_dump = -1;
	g_os.id = 0;
	g_os.live_counter = 0;
	g_os.chk_counter = 0;
	g_os.n_players = 0;
	g_os.p_ids = 0;
	g_os.verb = 0;
	g_os.buff.i = 0;
	g_os.buff.n = 0;
	players_init();
	dlst_cir_init(&g_procs);
}
