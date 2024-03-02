# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 18:05:35 by barjimen          #+#    #+#              #
#    Updated: 2024/03/02 17:20:43 by barjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- Primera parte ----------------------------------
 #---Ejecutables
 
	NAME_C	:= client
	NAME_S	:= server

#---Carpetas

	SRC_DIR		:=		src/
	SRC_DIR_C	:=		src/src_c/
	SRC_DIR_S	:=		src/src_s/
	OBJ_DIR		:=		obj/
	OBJ_DIR_C	:=		obj/obj_c/
	OBJ_DIR_S	:=		obj/obj_s/
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
	
	SRC_FILES_C	:=		cliente  \
						c_msg	 \
						
	SRC_FILES_S	:=		servidor \

#--- Variables de los archivos

	SRC_C		=		$(addprefix $(SRC_DIR_C), $(addsuffix .c, $(SRC_FILES_C)))
	OBJ_C		=		$(addprefix $(OBJ_DIR_C), $(addsuffix .o, $(SRC_FILES_C)))
	DEPS_C		=		$(addprefix $(OBJ_DIR_C), $(addsuffix .d, $(SRC_FILES_C)))
	SRC_S		=		$(addprefix $(SRC_DIR_S), $(addsuffix .c, $(SRC_FILES_S)))
	OBJ_S		=		$(addprefix $(OBJ_DIR_S), $(addsuffix .o, $(SRC_FILES_S)))
	DEPS_S		=		$(addprefix $(OBJ_DIR_S), $(addsuffix .d, $(SRC_FILES_S)))
	INCS		=		$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
	
#--- Comandos

RM				=		rm -f

#--- Caché

OBJF_C			=		.cache_exists_c
OBJF_S			=		.cache_exists_s

#---------------------------------- Segunda parte ----------------------------------
all:	makelibs
			@$(MAKE) $(NAME_C)
			@$(MAKE) $(NAME_S)

makelibs:
			@$(MAKE) -C $(LFT_DIR)

-include	${DEPS_C}
$(NAME_C):	$(OBJ_C)
			@$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)


-include	${DEPS_S}
$(NAME_S):	$(OBJ_S)
			@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)

bonus:
			@$(MAKE)	all

$(OBJ_DIR_C)%.o:	$(SRC_DIR_C)%.c $(INCS) | $(OBJF_C)
			@$(CC) $(CFLAGS) -MMD -c $< -o $@


$(OBJ_DIR_S)%.o:	$(SRC_DIR_S)%.c $(INCS) | $(OBJF_S)
			@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF_C):
			@mkdir -p $(OBJ_DIR_C)
$(OBJF_S):
			@mkdir -p $(OBJ_DIR_S)
			
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
	
	