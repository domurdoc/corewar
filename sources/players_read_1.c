#include "corewar.h"

static int	field_read(int fd, uint8_t *buf, ssize_t len, int (*ch)(uint8_t*))
{
	if (read(fd, buf, len) < len)
		return (0);
	if (ch && !ch(buf))
		return (0);
	return (1);
}

static void	player_read(t_player *p)
{
	int	fd;

	if ((fd = open(p->file_name, O_RDONLY)) < 0)
		exit_(ERR_SYS, p->file_name);
	if (!field_read(fd, (uint8_t*)&p->magic, sizeof(uint32_t), good_magic))
		exit_(ERR_READ_MAGIC, NULL);
	if (!field_read(fd, (uint8_t*)p->prog_name, PROG_NAME_LENGTH, good_str))
		exit_(ERR_READ_PNAME, NULL);
	if (!field_read(fd, (uint8_t*)&p->magic, sizeof(uint32_t), good_none))
		exit_(ERR_READ_NONE, NULL);
	if (!field_read(fd, (uint8_t*)&p->prog_size, sizeof(uint32_t), good_size))
		exit_(ERR_READ_PSIZE, NULL);
	if (!field_read(fd, (uint8_t*)p->comment, COMMENT_LENGTH, good_str))
		exit_(ERR_READ_COMM, NULL);
	if (!field_read(fd, (uint8_t*)&p->magic, sizeof(uint32_t), good_none))
		exit_(ERR_READ_NONE, NULL);
	if (!field_read(fd, (uint8_t*)p->prog_code, p->prog_size, NULL))
		exit_(ERR_READ_PCODE, NULL);
	if (read(fd, (uint8_t*)&p->magic, 1) == 1)
		exit_(ERR_READ_PCODE, NULL);
	if (close(fd))
		exit_(ERR_SYS, NULL);
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
