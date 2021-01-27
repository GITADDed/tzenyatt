#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/errno.h>

typedef	enum	e_abbrev
{
	none = -1
}				t_abbrev;

typedef struct	s_printf
{
	char		minuspf;
	char		zeropf;
	char		typepf;
	int			widthpf;
	int			precisionpf;
}				t_printf;

int				ft_printf(const char *str, ...);
char			ft_parce_flag(t_printf *prc, char **str);
char			ft_parce_width(t_printf *prc, char **str, va_list args);
char			ft_parce_prec(t_printf *prc, char **str, va_list args);
t_printf		*ft_get_spec(char **str, va_list args);
t_printf		*ft_init_spec(void);
void			ft_putchar(char c);
int				ft_pr_wid_str(t_printf *prc, int strlen);
int				ft_proc_c(t_printf *prc, va_list args);
int				ft_proc_s(t_printf *prc, va_list args);
int				ft_pr_prec_str(t_printf *prc, char *str);
int				ft_strlen(char *s);
int				ft_proc_di(t_printf *prc, va_list args);
int				ft_pr_wp_nbr(t_printf *prc, uintmax_t nbr, int base, char sign);
int				ft_nlen_b(uintmax_t nbr, int base);
int				ft_pr_width(t_printf *prc, int len, char sign);
int				ft_pr_prec(t_printf *prc, int len, char sign);
void			ft_putnbr_b(uintmax_t nbr, int base, char *str);
int				ft_pr_type(t_printf *prc, va_list args, int *result);
int				ft_pr_result(char *str, va_list args, int *result);
int				ft_proc_ux(t_printf *prc, va_list args);
int				ft_proc_p(t_printf *prc, va_list args);
void			ft_putstr(char *str);

#endif
