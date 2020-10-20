#include "corewar.h"

int	main(int ac, char **av)
{
	t_vm	vm;

	vm_init(&vm);
	input_parse(ac, av);
	players_read();
	arena_init();
	arena_run();
	exit_(SUCC, NULL);
}
