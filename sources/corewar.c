#include "corewar.h"

t_os		g_os;
t_dlst_cir	g_procs;

int	main(int ac, char **av)
{
	vm_init();
	input_parse(ac, av);
	players_read();
	arena_init();
	arena_run();
	exit_(SUCC, NULL);
}
