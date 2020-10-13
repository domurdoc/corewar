#ifndef COREWAR_T_H
# define COREWAR_T_H
# include "libft.h"
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define MEM_SIZE			(4*1024)
# define REG_NUMBER			16
# define REG_SIZE			4
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define MAX_PLAYERS		4
# define BUFF_SIZE			4096

typedef struct s_instr	t_instr;

typedef	struct	s_buff
{
	char		s[BUFF_SIZE];
	uint32_t	i;
	uint32_t	n;
}				t_buff;

typedef struct	s_player
{
	char		*file_name;
	uint32_t	magic;
	char		prog_name[PROG_NAME_LENGTH + 1];
	uint32_t	prog_size;
	char		comment[COMMENT_LENGTH + 1];
	uint8_t		prog_code[CHAMP_MAX_SIZE];
}				t_player;

typedef struct	s_arg
{
	int32_t		raw_val;
	int32_t		val;
	uint32_t	idx;
	uint8_t		code;
}				t_arg;

typedef struct	s_ci
{
	t_instr		*instr;
	t_arg		args[3];
	uint32_t	cycles_to_exec;
}				t_ci;

typedef struct	s_proc
{
	uint32_t	id;
	uint8_t		reg[REG_NUMBER][REG_SIZE];
	uint32_t	pc;
	uint32_t	pc_adv;
	uint8_t		cf;
	uint32_t	lc;
	t_ci		ci;
}				t_proc;

struct			s_instr
{
	char		*name;
	uint8_t		acb;
	uint8_t		n_args;
	uint8_t		types[3];
	uint32_t	n_ccls;
	uint8_t		dir_16;
	uint8_t		idx_mod;
	void		(*exec)(t_proc*);
	void		(*repr)(t_proc*);
};

typedef struct	s_os
{
	uint8_t		mem[MEM_SIZE];
	uint64_t	cycles_passed;
	uint64_t	ctd;
	uint64_t	cycles_to_check;
	uint64_t	cycles_to_dump;
	uint8_t		id;
	uint64_t	live_counter;
	uint64_t	chk_counter;
	uint8_t		n_players;
	t_player	players[MAX_PLAYERS];
	uint32_t	p_ids;
	uint8_t		verb;
	t_buff		buff;
}				t_os;

#endif
