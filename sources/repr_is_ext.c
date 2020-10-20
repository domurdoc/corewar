#include "corewar.h"

void	mul_repr(t_proc *proc)
{
	src_repr(&AR[0]);
	buff_str(" * ");
	src_repr(&AR[1]);
	buff_str(" = ");
	buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
	buff_str(" --> ");
	dst_repr(&AR[2]);
}

void	div_repr(t_proc *proc)
{
	src_repr(&AR[0]);
	buff_str(" / ");
	src_repr(&AR[1]);
	if (AR[1].val)
	{
		buff_str(" = ");
		buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
		buff_str(" --> ");
		dst_repr(&AR[2]);
	}
	else
	{
		buff_str(" (devision by zero - failed)");
	}
}

void	lsh_repr(t_proc *proc)
{
	src_repr(&AR[0]);
	buff_str(" << ");
	src_repr(&AR[1]);
	if (AR[1].val >= 0 && AR[1].val < 32)
	{
		buff_str(" = ");
		buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
		buff_str(" --> ");
		dst_repr(&AR[2]);
	}
	else
	{
		buff_str(" (left shift count must be [0..32] - failed)");
	}
}

void	rsh_repr(t_proc *proc)
{
	src_repr(&AR[0]);
	buff_str(" >> ");
	src_repr(&AR[1]);
	if (AR[1].val >= 0 && AR[1].val < 32)
	{
		buff_str(" = ");
		buff_number(*(int32_t*)proc->reg[AR[2].idx], 10);
		buff_str(" --> ");
		dst_repr(&AR[2]);
	}
	else
	{
		buff_str(" (left shift count must be [0..32] - failed)");
	}
}
