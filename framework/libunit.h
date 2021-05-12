#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# define UNKNOWN SIGUSR1
# define GREEN  "\x1b[32m"
# define RED    "\x1b[31m"
# define YELLOW "\x1b[33m"
# define CYAN   "\x1b[36m"
# define RESET  "\x1b[39m"

int						g_start;
typedef struct s_clist	t_clist;
struct		s_clist
{
	void	*data;
	t_clist	*next;
	t_clist	*prev;
};
typedef struct s_data
{
	char	*case_name;
	int		(*f_case)();
}	t_data;

t_clist	*ft_clstnew(void *data);
void	ft_clstadd_front(t_clist **lst, t_clist *new);
void	ft_clstadd_front(t_clist **lst, t_clist *new);
int		ft_setptr(void *dest, void *p);
void	err_exit(t_clist *lst, t_data *data);
void	load_test(t_clist **lst, char *case_name, int (*f_case)());
void	lst_clear(t_clist *lst);
void	lst_free_next(t_clist **lst, t_clist *next, void *data);
int		launch_tests(t_clist **lst, char *title);
int		print_result(char *case_name, int res);
int		case_result(t_clist *lst);
int		run_test(t_clist *lst, char *title);
size_t	my_strlen(char *s);

#endif