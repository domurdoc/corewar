#include "corewar.h"

void	mul(t_proc *proc)
{
	*(int32_t*)proc->reg[AR[2].idx] = AR[0].val * AR[1].val;
	CF_SET(*(int32_t*)proc->reg[AR[2].idx]);
}

void	div_(t_proc *proc)
{
	if (AR[1].val)
	{
		*(int32_t*)proc->reg[AR[2].idx] = AR[0].val / AR[1].val;
		CF_SET(*(int32_t*)proc->reg[AR[2].idx]);
	}
}

void	lsh(t_proc *proc)
{
	if (AR[1].val >= 0 && AR[1].val < 32)
		*(int32_t*)proc->reg[AR[2].idx] = AR[0].val << AR[1].val;
}

void	rsh(t_proc *proc)
{
	if (AR[1].val >= 0 && AR[1].val < 32)
		*(int32_t*)proc->reg[AR[2].idx] = AR[0].val >> AR[1].val;
}

void	rshh(t_proc *proc)
{
	if (AR[1].val >= 0 && AR[1].val < 32)
		*(int32_t*)proc->reg[AR[2].idx] = (uint32_t)AR[0].val >> AR[1].val;
}
