#include "corewar.h"

void	dst_repr(t_arg *arg)
{
	if (arg->code == REG_CODE)
	{
		buff_str("r");
		buff_number(arg->raw_val, 10);
	}
	else if (arg->code == IND_CODE)
		buff_number((int32_t)arg->idx, 10);
}

void	src_repr(t_arg *arg)
{
	buff_number(arg->val, 10);
	if (arg->code == DIR_CODE)
		return ;
	buff_str("(");
	dst_repr(arg);
	buff_str(")");
}
