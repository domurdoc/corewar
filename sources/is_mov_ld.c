#include "corewar.h"

void	ld(t_proc *proc)
{
	*(int32_t*)proc->reg[AR[1].idx] = AR[0].val;
	CF_SET(AR[0].val);
}

void	lld(t_proc *proc)
{
	ld(proc);
}

void	ldi(t_proc *proc)
{
	*(int32_t*)proc->reg[AR[2].idx] = src_ind(dst_ind(AR[0].val + AR[1].val, proc));
}

void	lldi(t_proc *proc)
{
	*(int32_t*)proc->reg[AR[2].idx] = src_ind(dst_ind((AR[0].val + AR[1].val) % IDX_MOD, proc));
}
