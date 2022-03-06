#ifndef TESTER_H
#define TESTER_H

typedef struct s_clist	t_clist;

void	capture_stdout(void);
char	*get_captured_stdout(void);
void	load_test(t_clist **lst, char *case_name, int (*f_case)());
int		launch_tests(t_clist **lst, char *title);
void	print_header(void);

#endif /* TESTER */
