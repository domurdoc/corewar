#include "corewar.h"

static void	do_procs(void)
{
	t_proc		*proc;
	t_dlst		*ptr;
	uint32_t	i;

	i = g_vm->procs.len;
	ptr = g_vm->procs.cur;
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
	ft_printf("Player %d (%s) won\n", g_vm->id,
		g_vm->players[g_vm->id - 1].prog_name);
	if (g_vm->dump)
		dump();
	exit_(SUCC, NULL);
}

static void	check_procs(void)
{
	t_proc		*proc;
	uint32_t	i;

	i = 0;
	while (i < g_vm->procs.len)
	{
		proc = g_vm->procs.cur->data;
		if (g_vm->cycles_passed - proc->lc >= g_vm->ctd)
		{
			verb_check_2(proc);
			free(dlst_cir_pop(&g_vm->procs));
		}
		else
		{
			g_vm->procs.cur = g_vm->procs.cur->next;
			i++;
		}
	}
}

static void	do_check(void)
{
	if (g_vm->cycles_to_check == 0 || g_vm->procs.len == 0)
		game_over();
	else if (g_vm->cycles_to_check-- == 1)
	{
		verb_check_1();
		check_procs();
		verb_check_3();
		g_vm->chk_counter++;
		if (g_vm->live_counter >= NBR_LIVE || g_vm->chk_counter > MAX_CHECKS)
		{
			g_vm->ctd = CYCLE_DELTA >= g_vm->ctd ? 0 : g_vm->ctd - CYCLE_DELTA;
			g_vm->chk_counter = 0;
		}
		g_vm->cycles_to_check = g_vm->ctd;
		g_vm->live_counter = 0;
	}
}

void		arena_run(void)
{
	while (g_vm->cycles_passed <= g_vm->cycles_to_dump)
	{
		g_vm->cycles_passed++;
		do_procs();
		do_check();
	}
	dump();
}
