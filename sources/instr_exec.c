#include "corewar.h"

static uint8_t	arg_init(t_arg *arg, uint8_t code, uint8_t type, t_proc *proc)
{
	static uint8_t	lens[4][2] = {{0, 0}, {REG_LEN, REG_LEN},
					{DIR_LEN, DIR_16_LEN}, {IND_LEN, IND_LEN}};
	static uint8_t	types[4] = {0, T_REG, T_DIR, T_IND};

	arg->code = code;
	arg->val = lens[code][proc->ci.instr->dir_16];
	arg->idx = proc->pc_adv;
	proc->pc_adv = IDX(proc->pc_adv + arg->val);
	if ((types[code] & type) == 0)
		return (1);
	if (code == REG_CODE && (g_os.mem[arg->idx] - 1 >= REG_NUMBER))
		return (1);
	if (type & SRC)
		arg_src(arg, proc);
	else
		arg_dst(arg, proc);
	return (0);
}

void			instr_exec(t_proc *proc)
{
	uint8_t	acb;
	uint8_t	err;
	uint8_t	i;

	if (!proc->ci.instr->acb)
	{
		acb = g_os.mem[proc->pc_adv++];
		proc->pc_adv = IDX(proc->pc_adv);
	}
	else
		acb = proc->ci.instr->acb;
	err = 0;
	i = -1;
	while (++i < proc->ci.instr->n_args)
		err |= arg_init(&proc->ci.args[i], (acb >> (0x6 - (i << 1))) & 0x3,
			proc->ci.instr->types[i], proc);
	if (!err)
		proc->ci.instr->exec(proc);
	verb_assembly(proc, err);
	proc->pc = proc->pc_adv;
}
