#include "corewar.h"

uint32_t	dst_ind(int32_t val, t_proc *proc)
{
	return (IDX(proc->pc + val));
}

void		arg_dst(t_arg *arg, t_proc *proc)
{
	arg->val = mem_ref(arg->idx, arg->val);
	if (arg->code == DIR_CODE)
		;
	else if (arg->code == REG_CODE)
		arg->idx = arg->val - 1;
	else if (proc->ci.instr->idx_mod)
		arg->idx = dst_ind(arg->val % IDX_MOD, proc);
	else
		arg->idx = dst_ind(arg->val, proc);
}
