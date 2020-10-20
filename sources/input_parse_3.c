#include "corewar.h"

void	option_is(int *ac, char ***av)
{
	if (*ac < 2)
		exit_(ERR_IS_FLAG, "usage: -is extended");
	if (ft_strequ(*(++*av), "extended"))
		g_vm->is_size = IS_SIZE_EXT;
	else
		exit_(ERR_IS_FLAG, "usage: -is extended");
	(*ac)--;
}
