#ifndef FT_LIST_H
#define FT_LIST_H
#include <stdbool.h>
#include <stddef.h>
typedef struct s_clist t_clist;

struct s_clist {
  void *data;
  t_clist *next;
  t_clist *prev;
};

bool ft_clst_isbegin(t_clist *lst);
bool ft_clst_isempty(t_clist *lst);
bool ft_clst_isend(t_clist *lst);
size_t ft_clst_size(t_clist *lst);
t_clist *ft_clst_last(t_clist *lst);
t_clist *ft_clst_pop(t_clist *lst);
t_clist *ft_clstfirst(t_clist *lst);
t_clist *ft_clstnew(void *data);
t_clist *ft_clstnew_add_back(t_clist *lst, void *content);
void *ft_clst_next(t_clist **lst);
void ft_clst_clear(t_clist **lst, void (*del)());
void ft_clst_insert(t_clist *lst, t_clist *newlst);
void ft_clst_insert_all(t_clist *dest, t_clist **srcptr, void (*del)());
void ft_clst_link(t_clist *front, t_clist *back);
void ft_clst_popdel(t_clist *deltarget, void (*del)());
void ft_clstadd_back(t_clist *sentinel, t_clist *newlst);
void ft_clstadd_front(t_clist *sentinel, t_clist *newlst);
void ft_clstdelone(t_clist *lst, void (*del)(void *));

#endif
