#include "ft_select.h"

void	current_position(int *x, int *y)
{
	char	buf[8];
	char	cmd[] = "\033[6n";
	int		i;
	int		a;
	char	*tmp;

	if (isatty(fileno(stdin)))
	{
		write(1, cmd, sizeof(cmd));
		read(0, buf, sizeof(buf));
	}
	i = 2;
	while (buf[i] && buf[i] != ';')
		i++;
	tmp = ft_strsub(buf, 2, i - 2);
	*y = ft_atoi(tmp);
	free(tmp);
	i++;
	a = i;
	while (buf[i] && buf[i] != 'R')
		i++;
	tmp = ft_strsub(buf, a, i - a);
	*x = ft_atoi(tmp);
	free(tmp);
}

int			go_horizontal(char *res, int x, int y, char c)
{
	if (c == '-')
	{
		if (x > 0)
			x--;
	}
	else if (c == '+')
	{
		if (x < tgetnum("co"))
			x++;
	}
	tputs(tgoto(res, x, y), 1, my_putchar);
	return (x);
}

int			go_vertical(char *res, int x, int y, char c)
{
	if (c == '-')
	{
		if (y > 0)
			y--;
	}
	else if (c == '+')
	{
		if (y < tgetnum("li"))
			y++;
	}
	tputs(tgoto(res, x, y), 1, my_putchar);
	return (y);
}

void		modifier_emplacement_curseur(char *buf, char *res, int *x, int *y)
{
	int		a;
	int		b;

	a = *x;
	b = *y;
	if (buf[1] == 91)
	{
		if (buf[2] == 65)//aller en haut
			b = go_vertical(res, a, b, '-');
		else if (buf[2] == 66)//aller en bas
			b = go_vertical(res, a, b, '+');
		else if (buf[2] == 67)//aller a droite
			a = go_horizontal(res, a, b, '+');
		else if (buf[2] == 68)//aller a gauche
			a = go_horizontal(res, a, b, '-');
	}
	*x = a;
	*y = b;
}

void		reset_cursor(char *res, int *x, int *y)
{
	int		a;
	int		b;

	current_position(&a, &b);
	a--;
	b--;
	*x = a;
	*y = b;
	tputs(tgoto(res, *x, *y), 1, my_putchar);
}

int			deplacer_cursor(void)
{
	char	buf[3];
	char	*area;
	char	*res = tgetstr("cm", NULL);
	int		x;
	int		y;

	reset_cursor(res, &x, &y);
	while (1)
	{
		read(0, buf, 3);
		if (buf[0] == 4)
		{
			printf("Ctrls+D, on quitte\n");
			return (0);
		}
		if (buf[0] == 27)
			modifier_emplacement_curseur(buf, res, &x, &y);
		else
		{
			write(1, &buf[0], 1);
			reset_cursor(res, &x, &y);
		}
		ft_bzero(buf, 3);
	}
	return (0);
}

