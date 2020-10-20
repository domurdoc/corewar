#include "corewar.h"

static void		players_arrange(char **fn, uint8_t n)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (g_vm->players[j].file_name)
			j++;
		g_vm->players[j].file_name = fn[i++];
	}
	i = 0;
	while (i < g_vm->n_players)
	{
		if (!g_vm->players[i++].file_name)
			exit_(ERR_N_FLAG, "players numbers must be contiguous");
	}
}

static uint8_t	flag(char *arg)
{
	static char	*flags[NFLAGS] = {"-n", "-dump", "-v", "-is"};
	uint8_t		i;

	i = 0;
	while (i < NFLAGS)
	{
		if (ft_strequ(arg, flags[i]))
			break ;
		i++;
	}
	return (i);
}

void			input_parse(int ac, char **av)
{
	static void	(*option[NFLAGS])(int*, char***) = {option_n, option_dump,
				option_verb, option_is};
	char		*file_names[MAX_PLAYERS];
	uint8_t		n;
	uint8_t		f;

	n = 0;
	while (--ac > 0)
	{
		av++;
		if ((f = flag(*av)) < NFLAGS)
			option[f](&ac, &av);
		else
			option_none(*av, file_names, &n);
	}
	if (!g_vm->n_players)
		option_help();
	players_arrange(file_names, n);
}
