#include "corewar.h"

void	st_repr(t_proc *proc)
{
	buff_str("store ");
	src_repr(&AR[0]);
	buff_str(" to ");
	dst_repr(&AR[1]);
}

void	sti_repr(t_proc *proc)
{
	buff_str("store ");
	src_repr(&AR[0]);
	buff_str(" to ");
	buff_number(dst_ind((AR[1].val + AR[2].val) % IDX_MOD, proc), 10);
}
