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
	ft_printf("%s\n", g_os.players[g_os.id - 1].prog_name);
	exit(EXIT_SUCCESS);
}

static void	check_procs(void)
{
	t_proc		*proc;
	uint32_t	i;

	i = 0;
	while (i < g_procs.len)
	{
		proc = g_procs.cur->data;
		if (proc->lc == 0)
			free(dlst_cir_pop(&g_procs));
		else
		{
			proc->lc = 0;
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
		check_procs();
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

void		game_run(void)
{
	while (g_os.cycles_passed <= g_os.cycles_to_dump)
	{
		do_procs();
		do_check();
		g_os.cycles_passed++;
	}
	dump();
}
