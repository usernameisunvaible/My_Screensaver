##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	main.c	\
		screen_saver_ext.c	\
		screen_saver_1/my_screensaver1_2.c	\
		screen_saver_1/my_screensaver1.c	\
		screen_saver_2/creat_lab_1.c	\
		screen_saver_2/creat_lab_2.c	\
		screen_saver_2/creat_lab_3.c	\
		screen_saver_2/draw_lab.c	\
		screen_saver_2/fadeout.c	\
		screen_saver_2/main_second.c	\
		screen_saver_2/my_screensaver2.c	\
		screen_saver_2/recursion_solving.c	\
		screen_saver_2/rgb_lab.c	\
		screen_saver_3/my_screensaver3.c	\
		screen_saver_4/init_struct.c	\
		screen_saver_4/jump_ball.c	\
		screen_saver_4/my_screensaver4.c	\
		screen_saver_5/my_screensaver5.c	\
		my_select_rgba.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sceensaver

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lm

all:	$(NAME)

clean:
	rm -fr $(OBJ)

fclean:	clean
	rm -fr $(NAME)

re:	fclean all
