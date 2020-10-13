#include "corewar.h"

void		option_n(int *ac, char ***av)
{
	int	n;

	if (g_os.n_players >= MAX_PLAYERS)
		exit_(ERR_N_PLAYERS, NULL);
	if (*ac < 3)
		exit_(ERR_N_FLAG, NULL);
	n = ft_atoi(*(++*av));
	if (n < 1 || n > MAX_PLAYERS)
		exit_(ERR_N_FLAG, NULL);
	if (g_os.players[n - 1].file_name)
		exit_(ERR_N_FLAG, NULL);
	g_os.players[n - 1].file_name = *(++*av);
	g_os.n_players++;
	(*ac) -= 2;
}

void		option_dump(int *ac, char ***av)
{
	int	n;

	if (*ac < 2)
		exit_(ERR_DUMP_FLAG, NULL);
	if (!is_number(*(++*av)))
		exit_(ERR_DUMP_FLAG, NULL);
	n = ft_atoi(**av);
	(*ac)--;
	if (n < 0)
		exit_(ERR_DUMP_FLAG, NULL);
	g_os.cycles_to_dump = n;
}

void		option_none(char *arg, char **file_names, uint8_t *n)
{
	if (g_os.n_players >= MAX_PLAYERS)
		exit_(ERR_N_PLAYERS, NULL);
	file_names[(*n)++] = arg;
	g_os.n_players++;
}

void		option_verb(int *ac, char ***av)
{
	int	n;

	if (*ac < 2)
		exit_(ERR_V_FLAG, NULL);
	if (!is_number(*(++*av)))
		exit_(ERR_V_FLAG, NULL);
	n = ft_atoi(**av);
	(*ac)--;
	if (n < 1 || n > 5)
		exit_(ERR_V_FLAG, NULL);
	else if (n < 4)
		g_os.verb |= 1 << (n - 1);
	else
		g_os.verb = n + 1;
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
		exit_(ERR_SYS, NULL);
	exit_(SUCC, NULL);
}
