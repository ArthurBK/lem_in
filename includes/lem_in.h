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

# include "libft.h"
#define RED  "\e[91m"
#define GRN  "\e[92m"
#define YEL  "\e[93m"
#define BLU  "\e[94m"
#define MAG  "\e[95m"
#define CYN  "\e[96m"
#define WHT  "\e[37m"
#define EOC  "\e[0m"

typedef struct  s_inf {
  size_t lemmings;
  char *start;
  char *end;
  char valid_map;
}               t_inf;

typedef struct  s_box {
  char         *name;
  struct s_link *links;
  struct s_box *next;
  int     weight;
}               t_box;


typedef struct  s_link {
  struct s_box *box;
  struct s_link *next;
}               t_link;

size_t	ft_strtab(char **tab);
int ft_isnumber(char *str);
size_t ft_push_box(t_inf	**inf, t_box **box, char *name, char *pos);
size_t ft_add_link(t_box **current_box, t_box **box_to_link);
size_t	ft_tagline(char **line,	t_inf	**inf, t_box **box);
size_t ft_pipe(char **line,	t_inf	**inf, t_box **box);
t_box *ft_select_box(char *name, t_box **boxes);

#endif
