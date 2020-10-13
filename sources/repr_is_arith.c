#include "corewar.h"

void	add_repr(t_proc *proc)
{
	src_repr(&AR[0]);
	buff_str(" + ");
	src_repr(&AR[1]);
	buff_str(" = ");
	buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
	buff_str(" --> ");
	dst_repr(&AR[2]);
}

void	sub_repr(t_proc *proc)
{
	src_repr(&AR[0]);
	buff_str(" - ");
	src_repr(&AR[1]);
	buff_str(" = ");
	buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
	buff_str(" --> ");
	dst_repr(&AR[2]);
}

void	and_repr(t_proc *proc)
{
	src_repr(&AR[0]);
	buff_str(" & ");
	src_repr(&AR[1]);
	buff_str(" = ");
	buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
	buff_str(" --> ");
	dst_repr(&AR[2]);
}

void	or_repr(t_proc *proc)
{
	src_repr(&AR[0]);
	buff_str(" | ");
	src_repr(&AR[1]);
	buff_str(" = ");
	buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
	buff_str(" --> ");
	dst_repr(&AR[2]);
}

void	xor_repr(t_proc *proc)
{
	src_repr(&AR[0]);
	buff_str(" ^ ");
	src_repr(&AR[1]);
	buff_str(" = ");
	buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
	buff_str(" --> ");
	dst_repr(&AR[2]);
}
