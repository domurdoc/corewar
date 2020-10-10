#include "corewar.h"

void	live(t_proc *proc)
{
	proc->lc = 1;
	if (AR[0].val <= -1 && AR[0].val >= -g_os.n_players)
		g_os.id = -AR[0].val;
	g_os.live_counter++;
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
		exit_(ERR_MEMORY, NULL);
	*new = *proc;
	new->pc_adv = dst_ind(AR[0].val % IDX_MOD, new);
	new->pc = new->pc_adv;
}

void	lfork(t_proc *proc)
{
	t_proc	*new;

	if (!(new = proc_add()))
		exit_(ERR_MEMORY, NULL);
	*new = *proc;
	new->pc_adv = dst_ind(AR[0].val, new);
	new->pc = new->pc_adv;
}

void	aff(t_proc *proc)
{
	(void)ft_dprintf(STDOUT_FILENO, "%c", AR[0].val);
}
