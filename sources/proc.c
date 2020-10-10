#include "corewar.h"

t_proc	*proc_add(void)
{
	t_proc	*new;

	if (!(new = malloc(sizeof(t_proc))))
		return (NULL);
	if (dlst_cir_push(&g_procs, new))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

void	proc_zer(t_proc *proc)
{
	(void)ft_memset((void*)proc->reg, 0, REG_NUMBER * REG_SIZE);
	proc->pc = 0;
	proc->cf = 0;
	proc->lc = 0;
	proc->ci.instr = NULL;
	proc->ci.cycles_to_exec = 0;
}
