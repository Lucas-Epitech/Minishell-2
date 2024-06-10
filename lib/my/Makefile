##
## EPITECH PROJECT, 2023
## Compile mylib
## File description:
## Makefile that compiles the lib
##

NAME    =    libmy.a

SRCS    =   my_putchar.c \
            my_isneg.c \
            my_putnbr.c \
            my_swap.c \
            my_putstr.c \
            my_strlen.c \
            my_getnbr.c \
            my_sort_int_array.c \
            my_compute_power_rec.c \
            my_compute_square_root.c \
            my_is_prime.c \
            my_find_prime_sup.c \
            my_strcpy.c \
            my_strncpy.c \
            my_revstr.c \
            my_strstr.c \
            my_strcmp.c \
            my_strncmp.c \
            my_strupcase.c \
            my_strlowcase.c \
            my_strcapitalize.c \
            my_str_isalpha.c \
            my_str_isnum.c \
            my_str_islower.c \
            my_str_isupper.c \
            my_str_isprintable.c \
            my_showstr.c \
            my_strcat.c \
            my_strncat.c \
            my_putnbr_base.c \
            my_putfloat.c \
            my_putlongnbr_base.c \
            my_putnbr_unsigned.c \
            my_printf.c \
            my_strdup.c \
            my_str_to_word_array.c	\
            my_ls.c	\

OBJS    =   $(SRCS:.c=.o)

CFLAGS    =    -Wall -Wextra

all:    $(NAME)
	@echo "Compilation de $(NAME) terminée."

$(NAME):    $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@rm -f *~
	@echo "Nettoyage terminé."

fclean: clean
	@rm -f $(NAME)
	@echo "Nettoyage complet terminé."

re: fclean all
	@echo "Recompilation terminée."

debug:
	@echo "DEBUG MODE DONE"
	$(CC) $(CFLAGS) $(SRCS) -lmy -L. -o $(NAME) -g3
