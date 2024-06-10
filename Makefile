##
## EPITECH PROJECT, 2023
## super compilator 3000_V2
## File description:
## Makefile
##

NAME    =    mysh

SRCS    =   $(wildcard *.c)

CFLAGS    =    -Wall -Wextra

all:
	@$(MAKE) -s -C lib/my -f Makefile all
	@cp lib/my/libmy.a .
	@$(CC) $(CFLAGS) $(SRCS) -lmy -L. -o $(NAME)

clean:
	@$(MAKE) -s -C lib/my -f Makefile clean

fclean:
	@$(MAKE) -s -C lib/my -f Makefile fclean
	@rm -f $(NAME)
	@rm -f libmy.a

re: fclean all

debug: all
	@$(CC) $(CFLAGS) $(SRCS) -lmy -L. -o $(NAME) -g3
