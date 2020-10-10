#include "corewar.h"

static char	*g_msg[N_MSG] = {
	"",
	"Input Error: number of players incorrect",
	"Input Error: invalid use of \"-n\" option",
	"Input Error: invalid use of \"-dump\" option",
	"",
	"Invalid Binary: magic-code incorrect",
	"Invalid Binary: name incorrect",
	"Invalid Binary: NULL",
	"Invalid Binary: program size incorrect",
	"Invalid Binary: comment incorrect",
	"Invalid Binary: program code incorrect",
	"",
	""
};

void	exit_(int code, char *str)
{
	if (errno)
		perror(str ? str : "Sys");
	else if (code)
		ft_dprintf(STDERR_FILENO, "%s\n", g_msg[code]);
	dlst_cir_del(&g_procs, free);
	exit(code ? EXIT_FAILURE : EXIT_SUCCESS);
}
