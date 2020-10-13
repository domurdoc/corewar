#include "corewar.h"

static void	do_procs(void)
{
	t_proc		*proc;
	t_dlst		*ptr;
	uint32_t	i;

	i = g_procs.len;
	ptr = g_procs.cur;
	while (i--)
	{
		proc = ptr->data;
		if (proc->ci.cycles_to_exec == 0)
			instr_fetch(proc);
		if (proc->ci.cycles_to_exec && proc->ci.cycles_to_exec-- == 1)
			instr_exec(proc);
		ptr = ptr->next;
	}
}

static void	game_over(void)
{
	buff_flush();
	ft_printf("Player %d (%s) won\n", g_os.id,
		g_os.players[g_os.id - 1].prog_name);
	exit_(SUCC, NULL);
}

static void	check_procs(void)
{
	t_proc		*proc;
	uint32_t	i;

	i = 0;
	while (i < g_procs.len)
	{
		proc = g_procs.cur->data;
		if (g_os.cycles_passed - proc->lc >= g_os.ctd)
		{
			verb_check_2(proc);
			free(dlst_cir_pop(&g_procs));
		}
		else
		{
			g_procs.cur = g_procs.cur->next;
			i++;
		}
	}
}

static void	do_check(void)
{
	if (g_os.cycles_to_check == 0 || g_procs.len == 0)
		game_over();
	else if (g_os.cycles_to_check-- == 1)
	{
		verb_check_1();
		check_procs();
		verb_check_3();
		g_os.chk_counter++;
		if (g_os.live_counter >= NBR_LIVE || g_os.chk_counter > MAX_CHECKS)
		{
			g_os.ctd = CYCLE_DELTA >= g_os.ctd ? 0 : g_os.ctd - CYCLE_DELTA;
			g_os.chk_counter = 0;
		}
		g_os.cycles_to_check = g_os.ctd;
		g_os.live_counter = 0;
	}
}

void		arena_run(void)
{
	while (g_os.cycles_passed <= g_os.cycles_to_dump)
	{
		g_os.cycles_passed++;
		do_procs();
		do_check();
	}
	dump();
}
