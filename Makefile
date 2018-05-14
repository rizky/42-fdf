# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 20:07:00 by rnugroho          #+#    #+#              #
#    Updated: 2018/05/14 22:23:48 by rnugroho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= fdf
FILES:= ft_fdf

# ----- Libft ------
LFTDIR:=./libft
LFTFLAG:=-L $(LFTDIR) -l ft
LFTINC:=-I $(LFTDIR)/include
# ==================

# ----- MinilibX ------
MLXDIR:=./minilibx
MLXFLAG:=-L $(MLXDIR) -l mlx -framework OpenGL -framework AppKit
MLXINC:=-I $(MLXDIR)
# ==================

# ------------------
COMPILER:=gcc
SRCPATH:=src/
HDRPATH:=include/
CCHPATH:=obj/
IFLAGS:=-I $(HDRPATH) $(LFTINC) $(MLXINC)
LFLAGS:=$(LFTFLAG) $(MLXFLAG)
CFLAGS:=-Wall -Wextra $(IFLAGS)
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) -o $(NAME)
	@echo $(GREEN) " - OK" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

libft:
	@echo $(PURPLE) " - Compiling libft/src/* to libft/obj/*" $(PURPLE)
	@cd $(LFTDIR) && $(MAKE) -s

minilibx:
	@echo $(PURPLE) " - Compiling minilibx" $(PURPLE)
	@cd $(MLXDIR) && $(MAKE) -s

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

debug: $(NAME)
	@echo "Files :" $(FILES)
	@$(COMPILER) -g $(IFLAGS) $(SRC) $(LFLAGS) -o $(NAME)

norm:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v	Norme -B1 || true
	@echo $(END)
	@cd $(LFTDIR) && $(MAKE) norm

.PHONY: all clean fclean re test norme