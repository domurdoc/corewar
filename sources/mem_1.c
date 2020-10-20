#include "corewar.h"

void	mem_read(uint32_t idx, uint8_t *dst, uint8_t len)
{
	idx += len;
	while (len--)
	{
		idx = IDX(idx - 1);
		*dst++ = g_vm->mem[idx];
	}
}

void	mem_write(uint32_t idx, uint8_t *src, uint8_t len)
{
	idx += len;
	while (len--)
	{
		idx = IDX(idx - 1);
		g_vm->mem[idx] = *src++;
	}
}
