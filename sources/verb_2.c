#include "corewar.h"

void	verb_check_1(void)
{
	if (g_vm->verb & 0x8)
	{
		buff_str("\nCHECKPOINT: cycle ");
		buff_number(g_vm->cycles_passed, 10);
		buff_str(", ctd ");
		buff_number(g_vm->ctd, 10);
		buff_str(", lc ");
		buff_number(g_vm->live_counter, 10);
		buff_str(", procs ");
		buff_number(g_vm->procs.len, 10);
		buff_str("\nKILLED PROCESSES:\n");
		g_vm->buff.n = 0;
	}
}

void	verb_check_2(t_proc *proc)
{
	if (g_vm->verb & 0x8)
	{
		buff_str(" P");
		buff_number(proc->id, 10);
		buff_str(" (not responding for ");
		buff_number(g_vm->cycles_passed - proc->lc, 10);
		buff_str(" cycles)\n");
	}
}

void	verb_check_3(void)
{
	if (g_vm->verb & 0x8)
	{
		if (!g_vm->buff.n)
			buff_str(" (none)\n\n");
		else
			buff_str("\n");
	}
}
