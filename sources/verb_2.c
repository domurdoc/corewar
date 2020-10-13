#include "corewar.h"

void	verb_check_1(void)
{
	if (g_os.verb & 0x4)
	{
		buff_str("\nCHECKPOINT: cycle ");
		buff_number(g_os.cycles_passed, 10);
		buff_str(", CTD = ");
		buff_number(g_os.ctd, 10);
		buff_str("\nPROCESSES KILLED:\n");
		g_os.buff.n = 0;
	}
}

void	verb_check_2(t_proc *proc)
{
	if (g_os.verb & 0x4)
	{
		buff_str(" P");
		buff_number(proc->id, 10);
		buff_str(" (not responding for ");
		buff_number(g_os.cycles_passed - proc->lc, 10);
		buff_str(" cycles)\n");
	}
}

void	verb_check_3(void)
{
	if (g_os.verb & 0x4)
	{
		if (!g_os.buff.n)
			buff_str(" (none)\n\n");
		else
			buff_str("\n");
	}
}
