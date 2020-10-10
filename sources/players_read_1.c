#include "corewar.h"

static int	field_read(int fd, uint8_t *buf, ssize_t nbytes, int (*check)(uint8_t*))
{
	if (read(fd, buf, nbytes) < nbytes)
		return (0);
	if (check && !check(buf))
		return (0);
	return (1);
}

static void	player_read(t_player *p)
{
	int	fd;

	if ((fd = open(p->file_name, O_RDONLY)) < 0)
		exit(EXIT_FAILURE);
	if (!field_read(fd, (uint8_t*)&p->magic, sizeof(uint32_t), good_magic))
		exit(EXIT_FAILURE);
	if (!field_read(fd, (uint8_t*)p->prog_name, PROG_NAME_LENGTH, good_str))
		exit(EXIT_FAILURE);
	if (!field_read(fd, (uint8_t*)&p->magic, sizeof(uint32_t), good_none))
		exit(EXIT_FAILURE);
	if (!field_read(fd, (uint8_t*)&p->prog_size, sizeof(uint32_t), good_size))
		exit(EXIT_FAILURE);
	if (!field_read(fd, (uint8_t*)p->comment, COMMENT_LENGTH, good_str))
		exit(EXIT_FAILURE);
	if (!field_read(fd, (uint8_t*)&p->magic, sizeof(uint32_t), good_none))
		exit(EXIT_FAILURE);
	if (!field_read(fd, (uint8_t*)p->prog_code, p->prog_size, NULL))
		exit(EXIT_FAILURE);
	if (close(fd))
		exit(EXIT_FAILURE);
}

void		players_read(void)
{
	uint8_t	i;

	i = 0;
	while (i < g_os.n_players)
	{
		player_read(&g_os.players[i]);
		i++;
	}
}
