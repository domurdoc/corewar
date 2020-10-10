#include "corewar.h"

static int	name_check(char *name)
{
	size_t	l;

	l = ft_strlen(name);
	if (l < EXT_LEN + 1)
		return (0);
	if (!ft_strequ(name + l - EXT_LEN, EXT))
		return (0);
	return (1);
}

void		option_n(int *ac, char ***av)
{
	int	n;

	if (g_os.n_players >= MAX_PLAYERS)
		exit(EXIT_FAILURE);
	if (*ac < 3)
		exit(EXIT_FAILURE);
	n = ft_atoi(*(++*av));
	if (n < 1 || n > MAX_PLAYERS)
		exit(EXIT_FAILURE);
	if (g_os.players[n - 1].file_name)
		exit(EXIT_FAILURE);
	g_os.players[n - 1].file_name = *(++*av);
	if (!name_check(g_os.players[n - 1].file_name))
		exit(EXIT_FAILURE);
	g_os.n_players++;
	(*ac) -= 2;
}

void		option_dump(int *ac, char ***av)
{
	int	n;

	if (*ac < 2)
		exit(EXIT_FAILURE);
	n = ft_atoi(*(++*av));
	(*ac)--;
	g_os.cycles_to_dump = n;
}

void		option_none(char *arg, char **file_names, uint8_t *n)
{
	if (g_os.n_players >= MAX_PLAYERS)
		exit(EXIT_FAILURE);
	file_names[(*n)++] = arg;
	if (!name_check(arg))
		exit(EXIT_FAILURE);
	g_os.n_players++;
}
