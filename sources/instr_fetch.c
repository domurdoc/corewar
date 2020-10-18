#include "corewar.h"

static t_instr	g_is[16] =
{
	{"live", DIR_CODE << 6, 1, {SRC | T_DIR},
		10, 0, 1, live, live_repr},
	{"ld", 0, 2, {SRC | T_DIR | T_IND, T_REG},
		5, 0, 1, ld, ld_repr},
	{"st", 0, 2, {SRC | T_REG, T_REG | T_IND},
		5, 0, 1, st, st_repr},
	{"add", 0, 3, {SRC | T_REG, SRC | T_REG, T_REG},
		10, 0, 1, add, add_repr},
	{"sub", 0, 3, {SRC | T_REG, SRC | T_REG, T_REG},
		10, 0, 1, sub, sub_repr},
	{"and", 0, 3,
		{SRC | T_REG | T_DIR | T_IND, SRC | T_REG | T_DIR | T_IND, T_REG},
		6, 0, 1, and, and_repr},
	{"or", 0, 3,
		{SRC | T_REG | T_DIR | T_IND, SRC | T_REG | T_DIR | T_IND, T_REG},
		6, 0, 1, or, or_repr},
	{"xor", 0, 3,
		{SRC | T_REG | T_DIR | T_IND, SRC | T_REG | T_DIR | T_IND, T_REG},
		6, 0, 1, xor, xor_repr},
	{"zjmp", DIR_CODE << 6, 1, {SRC | T_DIR},
		20, 1, 1, zjmp, zjmp_repr},
	{"ldi", 0, 3, {SRC | T_REG | T_DIR | T_IND, SRC | T_REG | T_DIR, T_REG},
		25, 1, 1, ldi, ldi_repr},
	{"sti", 0, 3,
		{SRC | T_REG, SRC | T_REG | T_DIR | T_IND, SRC | T_REG | T_DIR},
		25, 1, 1, sti, sti_repr},
	{"fork", DIR_CODE << 6, 1, {SRC | T_DIR},
		800, 1, 1, fork_, fork_repr},
	{"lld", 0, 2, {SRC | T_DIR | T_IND, T_REG},
		10, 0, 0, lld, lld_repr},
	{"lldi", 0, 3, {SRC | T_REG | T_DIR | T_IND, SRC | T_REG | T_DIR, T_REG},
		50, 1, 1, lldi, lldi_repr},
	{"lfork", DIR_CODE << 6, 1, {SRC | T_DIR},
		1000, 1, 1, lfork, lfork_repr},
	{"aff", 0, 1, {SRC | T_REG},
		2, 0, 1, aff, aff_repr}
};

void	instr_fetch(t_proc *proc)
{
	uint8_t	instr_idx;

	instr_idx = g_os.mem[proc->pc_adv++] - 1;
	proc->pc_adv = IDX(proc->pc_adv);
	if (instr_idx <= 0xF)
	{
		proc->ci.instr = &g_is[instr_idx];
		proc->ci.cycles_to_exec = proc->ci.instr->n_ccls;
	}
	else
	{
		verb_assembly(proc, 1);
		proc->pc = proc->pc_adv;
	}
}
