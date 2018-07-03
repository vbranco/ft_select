#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "libft/libft.h"
#include <term.h>
#include <termios.h>
#include <curses.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>


#include <stdlib.h>
#include <stdio.h>



typedef struct		s_head_arg
{
	struct s_arg	*start;
}					t_head_arg;

typedef struct		s_arg
{
	char			*info;
	int				flag;
	struct s_arg	*next;
}					t_arg;

/*
**	FT_TOOLS_LST.c
*/
t_head_arg			*initialise_head(void);
t_arg				*initialise_arg(char *inf);
void				add_arg(t_head_arg *head, char *info);
void				remove_arg(t_head_arg *head, char *inf);
void				ft_dell_args(t_head_arg **head);

/*
**	FT_MOVE.c
*/
void		modifier_emplacement_curseur(char *buf, char *res, int *x, int *y);
void		reset_cursor(char *res, int *x, int *y);
int			deplacer_cursor(void);

/*
**	MAIN.c
*/
int			my_putchar(int c);



#endif