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
	struct s_arg	*end;
	int				fd;
	struct termios	term;
	unsigned short	li;
	unsigned short	co;
	int				nb_lines;
	int				nb_col;
}					t_head_arg;

typedef struct		s_arg
{
	char			*info;
	short int		flag;
	short int		pos;
/*
**	flag: s = selection
*/
	struct s_arg	*next;
	struct s_arg	*prev;
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
**	FT_MOVE_AND_DELL.c
*/
void				ft_deplace_cursor(t_head_arg *head, char *buf);
void				ft_deplace(t_head_arg *head, char dire);
int					ft_dell_arg(t_head_arg *head);

/*
**	MAIN.c
*/
void				ft_get_args(t_head_arg *head, int ac, char **av);
void				ft_verif_signal(void);
void				ft_display_size(int sig);


/*
**	FT_GET_INPUT.c
*/
void				ft_select_arg(t_head_arg *head);
t_arg				*ft_looking_for_position(t_head_arg *head);
void				ft_get_input(t_head_arg *head);

/*
**	FT_PRINTING.c
*/
void				ft_print_args(t_head_arg *head);
int					my_putchar(int c);
void				ft_print_out(t_head_arg *head);

/*
** FT_TERM.c
*/
int					ft_prepare_term(t_head_arg *head, int i);
void				ft_config_term(t_head_arg *head, int start);
int					ft_init_term(void);



#endif
