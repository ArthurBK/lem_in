/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:43:26 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/05 16:59:53 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

// to delete
#include <stdio.h>
//

# include "libft.h"
#define RED  "\e[91m"
#define GRN  "\e[92m"
#define YEL  "\e[93m"
#define BLU  "\e[94m"
#define MAG  "\e[95m"
#define CYN  "\e[96m"
#define WHT  "\e[37m"
#define EOC  "\e[0m"

typedef struct  s_link t_link;
typedef struct  s_box t_box;

typedef struct  s_inf {
  size_t lemmings;
  char *start;
  char *end;
  char valid_map;
}               t_inf;

typedef struct  s_box {
  char         *name;
  int           visited;
  struct s_link *links;
  struct s_box *next;
}               t_box;

typedef struct  s_link {
  struct s_box *box;
  struct s_link *next;
}               t_link;

typedef struct  s_path {
  size_t length;
  struct s_link *path;
  struct s_path *next;
}               t_path;

typedef struct  s_ant {
  int ant_id;
  struct s_link *current_box;
  struct s_ant *next;
}               t_ant;

// helpers
size_t	ft_strtab(char **tab);
int ft_isnumber(char *str);
t_box *ft_find_box(t_box **box, char *name);
t_link *ft_new_way(t_box *box);
t_path *ft_new_path(t_link *path, size_t length);
t_box *ft_new_box(char *name, int visited, t_link *links);
void ft_add_path(t_path **head, t_link *to_add);
void ft_add_link(t_link **head, t_link *to_add);
t_box *ft_add_box(t_box *current_box, t_box *box_to_link);
t_link *ft_add_and_cpy_link(t_link *head, t_box *to_add);
void ft_add_ant(t_ant **head, t_ant *to_add);
t_ant *ft_new_ant(t_link *current_box, int ant_id);

// parsers
size_t ft_push_box(t_inf	**inf, t_box **box, char *name, char *pos);
size_t	ft_tagline(char **line,	t_inf	**inf, t_box **box);
size_t ft_pipe(char **line,	t_inf	**inf, t_box **box);
t_box *ft_select_box(char *name, t_box **boxes);

// paths
t_path *ft_find_paths(t_box **box, t_inf **inf);
t_path *ft_eval_path(t_path *paths, t_link *new_way, t_box *current_box, t_box *end);

// resolution
void ft_lem_in(t_path **paths, t_inf **inf);


//fonctions bizarres a supprimer
void        hex_dump(void *ptr, size_t size);

#endif
