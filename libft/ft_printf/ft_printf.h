/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 19:37:01 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 19:05:50 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"
# include <wchar.h>

typedef struct		s_form
{
	int				size;
	char			*buf;
	char			type;
	char			length;
	char			elength;
	int				is_h;
	int				is_z;
	int				is_n;
	int				is_p;
	int				is_s;
	int				min;
	int				prec;
	int				zero;
}					t_form;

int					ft_printf(const char *format, ...);
/*
** Parsing
*/
int					ft_format(const char *format, va_list ap, int *size,
		t_form *form);
int					ft_percent(const char *format, t_form *form);
void				ft_init_struct(t_form *form);
void				ft_recup_type(const char *format, t_form *form);
void				ft_recup_flag(const char *format, t_form *form);
void				ft_recup_length(const char *format, t_form *form);
void				ft_recup_min(const char *format, t_form *form, va_list ap);
void				ft_recup_prec(const char *format, t_form *form, va_list ap);
/*
** Recup type
*/
int					ft_args(t_form *form, va_list ap);
int					ft_arg_c(va_list ap, t_form *form);
int					ft_arg_s(va_list ap, t_form *form);
int					ft_arg_d_i(va_list ap, t_form *form);
int					ft_arg_x_o(va_list ap, t_form *form);
int					ft_arg_p(va_list ap, t_form *form);
int					ft_arg_b(va_list ap, t_form *form);
/*
** fonctions de modif pour recuperer une chaine de caracteres
*/
void				ft_convert_base_uintmax(uintmax_t nb, int base,
		t_form *form, char *str);
void				ft_convert_base_intmax(intmax_t nb, int base,
		t_form *form, char *str);
int					ft_wchar(wchar_t wc, char *str);
int					ft_wstr(wchar_t *wstr, char *str, t_form *form);
int					ft_count_size(wchar_t *wstr);
void				ft_my_itoa(intmax_t nb, char *tmp);
void				ft_my_itoa2(uintmax_t nb, char *tmp);
void				ft_add_str_begin(char *s1, char *s2);
void				ft_add_str_end(char *s1, char *s2);
/*
** Buffer
*/
int					ft_size_nb2(uintmax_t nb);
void				ft_buffer_d_i(char *str, t_form *form);
void				ft_buffer_x_o(char *str, t_form *form);
void				ft_buffer_b(char *str, t_form *form);
void				ft_buffer_s(char *str, t_form *form);
int					ft_buffer_c(char *str, t_form *form);
int					ft_precision(char *str, t_form *form);
void				ft_d_neg(char *str, t_form *form);
void				ft_d_prec(char *str, t_form *form);
int					ft_zero(char *str);
void				ft_x_prec(char *str, char *c, t_form *form);
void				ft_p_min(const char *format, t_form *form);
#endif
