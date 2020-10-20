#include "corewar.h"

void	live(t_proc *proc)
{
	proc->lc = g_vm->cycles_passed;
	if (AR[0].val <= -1 && AR[0].val >= -g_vm->n_players)
	{
		g_vm->id = -AR[0].val;
		if (!g_vm->verb && !g_vm->dump)
		{
			buff_str("A process shows that player ");
			buff_number(g_vm->id, 10);
			buff_str(" (");
			buff_str(g_vm->players[g_vm->id - 1].prog_name);
			buff_str(") is alive\n");
		}
	}
	g_vm->live_counter++;
}

void	zjmp(t_proc *proc)
{
	if (proc->cf)
		proc->pc_adv = dst_ind(AR[0].val % IDX_MOD, proc);
}

void	fork_(t_proc *proc)
{
	t_proc	*new;

	if (!(new = proc_add()))
		exit_(ERR_SYS, NULL);
	*new = *proc;
	new->id = g_vm->p_ids;
	new->pc_adv = dst_ind(AR[0].val % IDX_MOD, new);
	new->pc = new->pc_adv;
}

void	lfork(t_proc *proc)
{
	t_proc	*new;

	if (!(new = proc_add()))
		exit_(ERR_SYS, NULL);
	*new = *proc;
	new->id = g_vm->p_ids;
	new->pc_adv = dst_ind(AR[0].val, new);
	new->pc = new->pc_adv;
}

void	aff(t_proc *proc)
{
	if (!g_vm->verb && !g_vm->dump)
		(void)ft_printf("%c\n", AR[0].val);
}
