# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 19:28:21 by mhonchar          #+#    #+#              #
#    Updated: 2019/07/21 19:27:18 by mhonchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = GUImp
LIB_NAME = libft.a
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/
LIBFT_DIR = libft/


LIB = 	$(addprefix $(LIBFT_DIR), $(LIB_NAME)) \
		-L./libsdl/lib -lSDL2 
		# -L./libsdl_image/lib -lSDL2_image \
		# -L./libsdl_ttf/lib -lSDL2_ttf \
		# -L./libsdl_mixer/lib -lSDL2_mixer

SRC_FILES =		main.c \
				error_handler.c \
				sdl_init.c


				
				

HEADERS = 		$(INC_DIR)guimp.h \
				$(INC_DIR)error_handler.h \
				$(LIBFT_DIR)libft.h \
				libsdl/include/SDL2/SDL.h 
				# libsdl_image/include/SDL2/SDL_image.h \
				# libsdl_ttf/include/SDL2/SDL_ttf.h \
				# libsdl_mixer/include/SDL2/SDL_mixer.h

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
INC = 	-I $(INC_DIR) \
		-I $(LIBFT_DIR) \
		-I libsdl/include/SDL2/ 
		# -I libsdl_image/include/SDL2/ \
		# -I libsdl_ttf/include/SDL2/ \
		# -I libsdl_mixer/include/SDL2/
C_RED = \033[31m
C_GREEN = \033[32m
C_MAGENTA = \033[35m
C_NONE = \033[0m

all: $(NAME)

$(NAME): $(HEADERS) $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(OBJ_DIR):
	@mkdir obj
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

clean:
	@rm -rf $(OBJ_DIR)*
	@make fclean -C $(LIBFT_DIR)
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all

norm:
	@norminette $(SRC) $(HEADERS)