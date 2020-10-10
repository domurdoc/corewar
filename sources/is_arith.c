#include "corewar.h"

void	add(t_proc *proc)
{
	*(int32_t*)proc->reg[AR[2].idx] = AR[0].val + AR[1].val;
	CF_SET(*(int32_t*)proc->reg[AR[2].idx]);
}

void	sub(t_proc *proc)
{
	*(int32_t*)proc->reg[AR[2].idx] = AR[0].val - AR[1].val;
	CF_SET(*(int32_t*)proc->reg[AR[2].idx]);
}

void	and(t_proc *proc)
{
	*(int32_t*)proc->reg[AR[2].idx] = AR[0].val & AR[1].val;
	CF_SET(*(int32_t*)proc->reg[AR[2].idx]);
}

void	or(t_proc *proc)
{
	*(int32_t*)proc->reg[AR[2].idx] = AR[0].val | AR[1].val;
	CF_SET(*(int32_t*)proc->reg[AR[2].idx]);
}

void	xor(t_proc *proc)
{
	*(int32_t*)proc->reg[AR[2].idx] = AR[0].val ^ AR[1].val;
	CF_SET(*(int32_t*)proc->reg[AR[2].idx]);
}
