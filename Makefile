# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 18:05:35 by barjimen          #+#    #+#              #
#    Updated: 2024/02/08 20:52:01 by barjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- Primera parte ----------------------------------
 #---Ejecutables
 
	NAME	:= client
# lNAME	:= server

#---Carpetas

	SRC_DIR		:=		src/
	OBJ_DIR		:=		obj/
	LIB_DIR		:=		lib/
	INC_DIR		:=		inc/
	LFT_DIR		:=		$(LIB_DIR)libft/
#---Estos anteriores serían para uno
	
#---Compilador

	cc			:=		gcc
	CFLAGS		:=		-g -Wall -Wextra -Werror
	HEADER		:=		-I$(INC_DIR) -I$(LFT_DIR)

#--- .a de la LIBFT

	LIBFT		:=		$(LFT_DIR)libft.a

#--- .C
	
	SRC_FILES	:=		hola	\

#--- Variables de los archivos

	SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
	OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
	DEPS		=		$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
	INCS		=		$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
	
#--- Comandos

RM				=		rm -f

#--- Caché

OBJF			=		.cache_exists

#---------------------------------- Segunda parte ----------------------------------
all:	makelibs
			@$(MAKE) $(NAME)

makelibs:
			@$(MAKE) -C $(LFT_DIR)

-include	${DEPS}
$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus:
			@$(MAKE)	all

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS) | $(OBJF)
			@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
# $(LIBFT):
# 			@make -C $(LFT_DIR)

clean:
			@make clean -sC $(LFT_DIR)
			@$(RM) -rf $(OBJ_DIR)

fclean:		clean
			@$(RM) -f $(NAME)
			@make fclean -sC $(LFT_DIR)

re:			fclean
			@$(MAKE)

norminette:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true
			@norminette $(INC_DIR) | grep -v Norme -B1 || true

PHONY: all makelibs bone clean fclean re norminette
	
	