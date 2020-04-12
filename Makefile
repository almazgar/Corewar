# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 13:49:33 by avenonat          #+#    #+#              #
#    Updated: 2020/04/05 08:47:19 by almazg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			asm
LIBFT_A =		libft.a

COMP =			gcc -Wall -Werror -Wextra -I includes -I libft/includes -I libft/libft -c -o

OBJ_DIR =		obj/
SRC_DIR =		srcs/
LIBFT =			libft/

SRC =			asm.c init_ssl.c including_magic.c write_error.c parsing.c\
                skip_box.c check.c strncpy_dog.c check_exec.c compare.c\
                compare_2.c inst.c init_exec.c zero_struct.c recognize_1.c\
                skip_probel.c is_whitespace.c no_comment.c razborka.c\
                cne.c add_list.c choos_a.c data_to_list.c is_limit.c\
                choos_dig.c choos_str.c connecting_people.c move_posa.c\
                refresh_line.c is_registr.c error_lex.c\
                add_label.c take_label.c cnl.c zero_label.c\
                take_arg1.c no_separator.c take_arg2.c\
                inst_aff.c inst_lfork.c inst_fork.c inst_live.c\
                inst_zjmp.c inst_lld.c inst_ld.c inst_st.c\
                inst_add.c take_arg3.c inst_sub.c inst_and.c\
                inst_or.c inst_xor.c inst_ldi.c inst_lldi.c inst_sti.c\
                add_comand.c label_change.c label_search1.c label_search2.c\
                label_search3.c skolkovo.c check_name.c check_comment.c\
                arg_add.c kod_type_arg.c add_kta.c free_label.c free_exec.c\
                free_tfile.c line_to_write.c including_size.c negativ.c\

OBJ =			$(SRC:%.c=%.o)

SRC_PATH =   	$(SRC:%=$(SRC_DIR)%)
OBJ_PATH =		$(addprefix $(OBJ_DIR), $(OBJ))

all:			$(NAME)
				@echo "\\n\033[32;1m CORE-WAR COMPLETE \033[0m \\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		do_libft $(OBJ_DIR) $(OBJ_PATH)
				@gcc $(OBJ_PATH) *.a -o $(NAME) $(LIBFT_A)\
					-I includes -I libft/includes

$(OBJ_PATH):	$(SRC_PATH) includes/asm.h
				@$(MAKE) $(OBJ)

$(OBJ):			$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)
				@cp $(LIBFT)/$(LIBFT_A) .

clean:
				@/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
				@make -C $(LIBFT) clean
				@echo "\\n\033[32;1m Cleaned libft \033[0m"

fclean:			clean
				@/bin/rm -f $(NAME) $(LIBFT_A)
				@make -C $(LIBFT) fclean
				@echo "\033[32;1m Cleaned $(NAME) \033[0m \\n"

re: 			fclean all

.PHONY:			all clean fclean re