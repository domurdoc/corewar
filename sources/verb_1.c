#include "corewar.h"

static void	verb_proc_id(uint32_t id)
{
	char		temp[16];
	uint32_t	i;
	uint8_t		j;

	i = 0;
	j = 0;
	g_os.buff.n = 0;
	buff_str("P");
	nbr_recursion(temp, &i, id, 10);
	temp[i] = '\0';
	if (i > 5)
	{
		buff_str("..");
		buff_str(&temp[i - 3]);
	}
	else
	{
		while (j++ < 5 - i)
			buff_str(" ");
		buff_str(temp);
	}
	buff_str(" | ");
}

static void	verb_translation(t_ci *ci)
{
	static char	*s[4] = {"", REGISTER_STR, DIRECT_STR, ""};
	uint8_t		i;

	i = 0;
	buff_str(ci->instr->name);
	buff_str(" ");
	while (i < ci->instr->n_args)
	{
		buff_str(s[ci->args[i].code]);
		buff_number(ci->args[i].raw_val, 10);
		if (++i < ci->instr->n_args)
			buff_str(SEPARATOR_STR);
	}
}

static void	verb_padding(uint32_t s)
{
	uint32_t	i;
	uint32_t	pad;

	i = 0;
	pad = s - g_os.buff.n;
	while (i++ < pad)
		buff_str(" ");
	g_os.buff.n = 0;
}

void		verb_assembly(t_proc *proc)
{
	if (g_os.verb & 0x3)
	{
		verb_proc_id(proc->id);
		verb_translation(&proc->ci);
		if (g_os.verb & 0x2)
		{
			verb_padding(40);
			buff_number(proc->pc, 10);
			verb_padding(20);
			proc->ci.instr->repr(proc);
		}
		buff_str("\n");
	}
}