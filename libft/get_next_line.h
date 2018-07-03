/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/31 15:45:46 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 15:45:48 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#define EOF (-1)
#define BUFF_SIZE 4096

typedef	struct	s_getch
{
	int			fd;
	int			n;
	char		buf[BUFF_SIZE];
	char		*bufp;
}				t_getch;

int				get_next_line(const int fd, char **line);

#	endif
