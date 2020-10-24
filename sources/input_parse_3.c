#include "corewar.h"

static char	g_help[] = "NAME\n\
\t./corewar - the \"arena\" in which champions will be executed\n\
\t\t(virtual machine)\n\
\n\
SYNOPSIS\n\
\t./corewar [OPTION] [[-n number] champion1.cor] ...\n\
\n\
DESCRIPTION\n\
\n\
\t(without .cor-files)\n\
\t\tshow this man page and quit\n\
\n\
\t-dump SIZE CYCLE\n\
\t\tsuppress \"live\" and \"aff\" instructions output;\n\
\t\tat the end of CYCLE executions, dump the memory (SIZE bytes per line) on\n\
\t\tstandard output and quit the game; SIZE must be either 32 or 64;\n\
\t\tCYCLE must be a non-negative integer;\n\
\n\
\t-v MODE\n\
\t\tsuppress \"live\" and \"aff\" instructions output; verbosity mode with\n\
\t\tMODE equals:\n\
\t\t1 - show assembly instructions\n\
\t\t2 - mode 1 + show pc and description\n\
\t\t3 - mode 2 + show failed instructions\n\
\t\t4 - show checkups\n\
\t\t5 - (1 + 4) mode\n\
\t\t6 - (2 + 4) mode\n\
\t\t7 - (3 + 4) mode\n\
\n\
\t-n NUMBER FILE\n\
\t\tset the NUMBER of the next player from FILE; must be [1..4] without\n\
\t\trepetition\n\
\n\
\t-is extended\n\
\t\tuse extended set of instructions (mul, div, lsh, rsh, rshh)\n\
\n\
AUTHOR\n\
\tWritten by domurdoc";

void		option_help(void)
{
	ft_printf("%s\n", g_help);
	exit_(SUCC, NULL);
}
