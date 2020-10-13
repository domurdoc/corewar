#include "corewar.h"

void	ld_repr(t_proc *proc)
{
	buff_str("load ");
	src_repr(&AR[0]);
	buff_str(" to ");
	dst_repr(&AR[1]);
}

void	lld_repr(t_proc *proc)
{
	ld_repr(proc);
}

void	ldi_repr(t_proc *proc)
{
	buff_str("load ");
	buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
	buff_str("(");
	buff_number(dst_ind((AR[0].val + AR[1].val) % IDX_MOD, proc), 10);
	buff_str(") to ");
	dst_repr(&AR[2]);
}

void	lldi_repr(t_proc *proc)
{
	buff_str("load ");
	buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
	buff_str("(");
	buff_number(dst_ind((AR[0].val + AR[1].val), proc), 10);
	buff_str(") to ");
	dst_repr(&AR[2]);
}
