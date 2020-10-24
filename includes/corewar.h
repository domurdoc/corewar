#ifndef COREWAR_H
# define COREWAR_H
# include "corewar_t.h"
# include <errno.h>
# include <stdio.h>

# define IDX_MOD			(MEM_SIZE / 8)

# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define SRC				0x10

# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3

# define REG_LEN			1
# define DIR_LEN			4
# define DIR_16_LEN			2
# define IND_LEN			2

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		50
# define NBR_LIVE			21
# define MAX_CHECKS			10

# define COREWAR_EXEC_MAGIC	0xEA83F3

# define REGISTER_STR		"r"
# define DIRECT_STR			"%"
# define INDIRECT_STR		""
# define SEPARATOR_STR		", "

/*
** ERRORS
*/

# define ERR_SYS			-1
# define SUCC				0
# define ERR_N_PLAYERS		1
# define ERR_N_FLAG			2
# define ERR_DUMP_FLAG		3
# define ERR_V_FLAG			4
# define ERR_READ_MAGIC		5
# define ERR_READ_PNAME		6
# define ERR_READ_NONE		7
# define ERR_READ_PSIZE		8
# define ERR_READ_COMM		9
# define ERR_READ_PCODE		10

# define ERR_IS_FLAG		11

# define N_MSG				11

/*
** ***********
*/

# define AR					proc->ci.args
# define CF_SET(val)		proc->cf = (val) ? 0 : 1;
# define IDX(idx)			((idx) & 0xFFF)

# define NFLAGS				4

# define EXT				".cor"
# define EXT_LEN			4

# define IS_SIZE_STD		16
# define IS_SIZE_EXT		21

extern t_vm					*g_vm;

/*
** VM INIT *********************************************************************
*/

void		vm_init(t_vm *vm);

/*
** INPUT PARSING ***************************************************************
*/

void		input_parse(int ac, char **av);
void		option_n(int *ac, char ***av);
void		option_dump(int *ac, char ***av);
void		option_none(char *arg, char **file_names, uint8_t *n);
void		option_verb(int *ac, char ***av);
void		option_help(void);
void		option_is(int *ac, char ***av);

/*
** PLAYERS READING *************************************************************
*/

void		players_read(void);
int			good_magic(uint8_t *buf);
int			good_none(uint8_t *buf);
int			good_size(uint8_t *buf);

/*
** ARENA ***********************************************************************
*/

void		arena_init(void);
void		arena_run(void);

/*
** MEMORY **********************************************************************
*/

void		mem_read(uint32_t idx, uint8_t *dst, uint8_t len);
void		mem_write(uint32_t idx, uint8_t *src, uint8_t len);
int32_t		mem_ref(uint32_t idx, uint8_t len);

/*
** INSTRUCTION *****************************************************************
*/

void		instr_fetch(t_proc *proc);
void		instr_exec(t_proc *proc);

void		arg_dst(t_arg *arg, t_proc *proc);
void		arg_src(t_arg *arg, t_proc *proc);
uint32_t	dst_ind(int32_t val, t_proc *proc);
int32_t		src_ind(uint32_t idx);

/*
** INSTRUCTIONS SET ************************************************************
*/

void		live(t_proc *proc);
void		zjmp(t_proc *proc);
void		fork_(t_proc *proc);
void		lfork(t_proc *proc);
void		aff(t_proc *proc);

void		st(t_proc *proc);
void		sti(t_proc *proc);

void		ld(t_proc *proc);
void		lld(t_proc *proc);
void		ldi(t_proc *proc);
void		lldi(t_proc *proc);

void		add(t_proc *proc);
void		sub(t_proc *proc);
void		and(t_proc *proc);
void		or(t_proc *proc);
void		xor(t_proc *proc);

/*
** EXT
*/

void		mul(t_proc *proc);
void		div_(t_proc *proc);
void		lsh(t_proc *proc);
void		rsh(t_proc *proc);
void		rshh(t_proc *proc);

/*
** REPR ************************************************************************
*/

void		src_repr(t_arg *arg);
void		dst_repr(t_arg *arg);

void		live_repr(t_proc *proc);
void		zjmp_repr(t_proc *proc);
void		fork_repr(t_proc *proc);
void		lfork_repr(t_proc *proc);
void		aff_repr(t_proc *proc);

void		st_repr(t_proc *proc);
void		sti_repr(t_proc *proc);

void		ld_repr(t_proc *proc);
void		lld_repr(t_proc *proc);
void		ldi_repr(t_proc *proc);
void		lldi_repr(t_proc *proc);

void		add_repr(t_proc *proc);
void		sub_repr(t_proc *proc);
void		and_repr(t_proc *proc);
void		or_repr(t_proc *proc);
void		xor_repr(t_proc *proc);

/*
** EXT
*/

void		mul_repr(t_proc *proc);
void		div_repr(t_proc *proc);
void		lsh_repr(t_proc *proc);
void		rsh_repr(t_proc *proc);

/*
** PROCS ***********************************************************************
*/

t_proc		*proc_add(void);
void		proc_zer(t_proc *proc);

/*
** BUFFER **********************************************************************
*/

void		buff_flush(void);
void		buff_str(char *src);
void		buff_number(int32_t n, uint8_t base);

/*
** UTILITY *********************************************************************
*/

void		nbr_recursion(char *s, uint32_t *i, uint32_t n, uint8_t base);
int			is_number(char *str);

/*
** OUTPUT **********************************************************************
*/

void		dump(void);
void		verb(t_proc *proc);
void		verb_assembly(t_proc *proc, uint8_t err);
void		verb_check_1(void);
void		verb_check_2(t_proc *proc);
void		verb_check_3(void);

/*
** EXIT ************************************************************************
*/

void		exit_(int code, char *str);

#endif
