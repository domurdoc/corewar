#include "corewar.h"

static uint32_t	big_little_uint32(uint8_t *ptr)
{
	uint8_t		tmp[2];

	tmp[0] = ptr[3];
	tmp[1] = ptr[2];
	ptr[3] = ptr[0];
	ptr[2] = ptr[1];
	ptr[1] = tmp[1];
	ptr[0] = tmp[0];
	return (*(uint32_t*)ptr);
}

int				good_magic(uint8_t *buf)
{
	return (big_little_uint32(buf) == COREWAR_EXEC_MAGIC);
}

int				good_none(uint8_t *buf)
{
	return (big_little_uint32(buf) == 0);
}

int				good_size(uint8_t *buf)
{
	return (big_little_uint32(buf) <= CHAMP_MAX_SIZE);
}
