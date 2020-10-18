#include "corewar.h"

void		option_n(int *ac, char ***av)
{
	int	n;

	if (g_os.n_players >= MAX_PLAYERS)
		exit_(ERR_N_PLAYERS, "max 4");
	if (*ac < 3)
		exit_(ERR_N_FLAG, "2 parameters required: NUMBER and FILE");
	n = ft_atoi(*(++*av));
	if (n < 1 || n > MAX_PLAYERS)
		exit_(ERR_N_FLAG, "NUMBER must be [1..4]");
	if (g_os.players[n - 1].file_name)
		exit_(ERR_N_FLAG, "NUMBER must be unique");
	g_os.players[n - 1].file_name = *(++*av);
	g_os.n_players++;
	(*ac) -= 2;
}

void		option_dump(int *ac, char ***av)
{
	int	n;

	if (*ac < 3)
		exit_(ERR_DUMP_FLAG, "2 parameters required: SIZE and CYCLE");
	(*av)++;
	(*ac)--;
	if (ft_strequ(**av, "32"))
		g_os.dump = 32;
	else if (ft_strequ(**av, "64"))
		g_os.dump = 64;
	else
		exit_(ERR_DUMP_FLAG, "SIZE must be either 32 or 64");
	if (!is_number(*(++*av)))
		exit_(ERR_DUMP_FLAG, "CYCLE must be a non-negative integer");
	(*ac)--;
	n = ft_atoi(**av);
	if (n < 0)
		exit_(ERR_DUMP_FLAG, "CYCLE must be a non-negative integer");
	g_os.cycles_to_dump = n;
}

void		option_none(char *arg, char **file_names, uint8_t *n)
{
	if (g_os.n_players >= MAX_PLAYERS)
		exit_(ERR_N_PLAYERS, "max 4");
	file_names[(*n)++] = arg;
	g_os.n_players++;
}

void		option_verb(int *ac, char ***av)
{
	int	n;

	if (*ac < 2)
		exit_(ERR_V_FLAG, "1 parameter required: N");
	if (!is_number(*(++*av)))
		exit_(ERR_V_FLAG, "N must be [1..7]");
	n = ft_atoi(**av);
	(*ac)--;
	if (n < 1 || n > 7)
		exit_(ERR_V_FLAG, "N must be [1..7]");
	g_os.verb = 0;
	if (n > 4)
	{
		g_os.verb = 0x8;
		n -= 4;
	}
	g_os.verb |= 1 << (n - 1);
}

void		option_help(void)
{
	int		fd;
	char	*line;

	if ((fd = open("./resources/help", O_RDONLY)) < 0)
		exit_(ERR_SYS, "./resources/help");
	while (ft_gnl(fd, &line) > 0)
	{
		ft_dprintf(STDERR_FILENO, "%s\n", line);
		free(line);
	}
	if (close(fd) < 0)
		exit_(ERR_SYS, "./resources/help");
	exit_(SUCC, NULL);
}
