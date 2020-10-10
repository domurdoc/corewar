#include "corewar.h"

void	instr_fetch(t_proc *proc)
{
	uint8_t	instr_idx;

	instr_idx = g_os.mem[proc->pc_adv++] - 1;
	proc->pc_adv = IDX(proc->pc_adv);
	if (instr_idx <= 0xF)
	{
		proc->ci.instr = &g_is[instr_idx];
		proc->ci.cycles_to_exec = proc->ci.instr->n_ccls;
	}
	else
		proc->pc = proc->pc_adv;
}
