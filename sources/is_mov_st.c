#include "corewar.h"

void	st(t_proc *proc)
{
	if (AR[1].code == REG_CODE)
		*(int32_t*)proc->reg[AR[1].idx] = AR[0].val;
	else
		mem_write(AR[1].idx, proc->reg[AR[0].idx], REG_SIZE);
	CF_SET(AR[0].val);
}

void	sti(t_proc *proc)
{
	mem_write(dst_ind((AR[1].val + AR[2].val) % IDX_MOD, proc),
		proc->reg[AR[0].idx], REG_SIZE);
}
