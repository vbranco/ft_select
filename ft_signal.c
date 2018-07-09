#include "ft_select.h"

void		ft_verif_signal_1(void)
{
	signal(1, ft_stop);
	signal(2, ft_stop);
	signal(3, ft_stop);
	signal(4, ft_stop);
	signal(5, ft_stop);
	signal(6, ft_stop);
	signal(7, ft_stop);
	signal(8, ft_stop);
	signal(9, ft_stop);
	signal(10, ft_stop);
	signal(11, ft_stop);
	signal(12, ft_stop);
	signal(13, ft_stop);
	signal(14, ft_stop);
	signal(15, ft_stop);
	signal(16, ft_stop);
	signal(17, ft_stop);
	signal(SIGTSTP, ft_background);
	signal(SIGCONT, ft_frontground);
}

void		ft_verif_signal_2(void)
{
	signal(20, ft_stop);
	signal(21, ft_stop);
	signal(22, ft_stop);
	signal(23, ft_stop);
	signal(24, ft_stop);
	signal(25, ft_stop);
	signal(26, ft_stop);
	signal(27, ft_stop);
	signal(SIGWINCH, ft_display_size);
	signal(29, ft_stop);
	signal(30, ft_stop);
	signal(31, ft_stop);
}

void		ft_stop(int sig)
{
	ft_background(sig);
	close(head->fd);
	ft_dell_args(&head);
	exit(EXIT_SUCCESS);
}

void		ft_frontground(int sig)
{
	ft_verif_signal_1();
	ft_verif_signal_2();
	ft_config_term(head, 1);
	ft_display_size(0);
}

void		ft_background(int sig)
{
	ft_config_term(head, 0);
	if (sig == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, "\x1A");
	}
}
