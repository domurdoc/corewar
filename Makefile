CC = gcc
FLAGS = -Wall -Wextra -Werror -g3 -O3

# PROGRAM name

NAME = corewar

# PROGRAM src & obj

SRC_DIR = sources
OBJ_DIR = objects

SRC_NAMES = arena_init.c\
arena_run.c\
arg_dst.c\
arg_src.c\
buff.c\
corewar.c\
dump.c\
exit.c\
input_parse_1.c\
input_parse_2.c\
instr_exec.c\
instr_fetch.c\
instr.c\
is_arith.c\
is_control.c\
is_mov_ld.c\
is_mov_st.c\
mem_1.c\
mem_2.c\
players_read_1.c\
players_read_2.c\
proc.c\
repr_is_arith.c\
repr_is_control.c\
repr_is_mov_ld.c\
repr_is_mov_st.c\
repr.c\
utility.c\
verb_1.c\
verb_2.c\
vm_init.c

OBJ_NAMES = $(SRC_NAMES:.c=.o)

OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))

# PROGRAM headers

INCL_NAMES = corewar.h \
	corewar_t.h
INCL_DIR = includes

INCL = $(addprefix $(INCL_DIR)/, $(INCL_NAMES))

# LIBFT

LIB_NAME = libft.a
LIB_DIR = libft
LIB_INCL_DIR = $(addprefix $(LIB_DIR)/, $(INCL_DIR))
LIBFT = $(addprefix $(LIB_DIR)/, $(LIB_NAME))

# RULES

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBFT)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCL)
	$(CC) -I$(INCL_DIR) -I$(LIB_INCL_DIR) -o $@ -c $< $(FLAGS)

$(LIBFT): $(LIB_DIR)
	make -C $(LIB_DIR)

clean:	
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
