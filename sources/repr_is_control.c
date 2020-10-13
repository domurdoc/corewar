#include "corewar.h"

void	live_repr(t_proc *proc)
{
	if (AR[0].val <= -1 && AR[0].val >= -g_os.n_players)
	{
		buff_str("player ");
		buff_number(g_os.id, 10);
		buff_str(" is alive");
	}
	else
		buff_str("update live counter");
}

void	zjmp_repr(t_proc *proc)
{
	if (proc->cf)
	{
		buff_str("jump to ");
		buff_number(proc->pc_adv, 10);
	}
	else
		buff_str("jump failed");
}

void	fork_repr(t_proc *proc)
{
	buff_str("copy proc to ");
	buff_number(dst_ind(AR[0].val % IDX_MOD, proc), 10);
	buff_str(" (new proc ");
	buff_number(g_os.p_ids, 10);
	buff_str(")");
}

void	lfork_repr(t_proc *proc)
{
	buff_str("copy proc to ");
	buff_number(dst_ind(AR[0].val, proc), 10);
	buff_str(" (new proc ");
	buff_number(g_os.p_ids, 10);
	buff_str(")");
}

void	aff_repr(t_proc *proc)
{
	buff_str("print \\0x");
	buff_number((uint8_t)AR[0].val, 16);
}
