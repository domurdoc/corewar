#include "corewar.h"

static char	*g_msg[N_MSG] = {
	"Input Error: number of players incorrect (max 4)",
	"Input Error: invalid use of \"-n\" option",
	"Input Error: invalid use of \"-dump\" option",
	"Input Error: invalid use of \"-v\" option",
	"Invalid Binary: magic-code incorrect",
	"Invalid Binary: name incorrect",
	"Invalid Binary: NULL",
	"Invalid Binary: program size incorrect",
	"Invalid Binary: comment incorrect",
	"Invalid Binary: program code incorrect",
};

void	exit_(int code, char *str)
{
	if (errno)
		perror(str ? str : "Sys");
	else if (code > 0)
		ft_dprintf(STDERR_FILENO, "%s\n", g_msg[code - 1]);
	dlst_cir_del(&g_procs, free);
	exit(code ? EXIT_FAILURE : EXIT_SUCCESS);
}
