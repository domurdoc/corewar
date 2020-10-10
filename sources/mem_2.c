#include "corewar.h"

int32_t	ref_1(uint8_t *ptr)
{
	return (*ptr);
}

int32_t	ref_16(uint8_t *ptr)
{
	return (*(int16_t*)ptr);
}

int32_t	ref_32(uint8_t *ptr)
{
	return (*(int32_t*)ptr);
}

int32_t	mem_ref(uint32_t idx, uint8_t len)
{
	static int32_t	(*ref[5])(uint8_t*) = {NULL, ref_1, ref_16, NULL, ref_32};
	uint8_t			temp[REG_SIZE];

	mem_read(idx, temp, len);
	return (ref[len](temp));
}
