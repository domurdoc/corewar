#include "corewar.h"

int32_t	src_ind(uint32_t idx)
{
	return (mem_ref(idx, REG_SIZE));
}

void	arg_src(t_arg *arg, t_proc *proc)
{
	arg_dst(arg, proc);
	if (arg->code == DIR_CODE)
		arg->val = arg->raw_val;
	else if (arg->code == REG_CODE)
		arg->val = *(int32_t*)proc->reg[arg->idx];
	else if (arg->code == IND_CODE)
		arg->val = src_ind(arg->idx);
}
