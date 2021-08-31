/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:48:20 by mchun             #+#    #+#             */
/*   Updated: 2021/08/31 18:57:21 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		variable_expansion(t_darr *env, t_llist *list);

int		argv_split(t_llist *list);
char	**ft_split_quote(t_node *node);

int		check_function_type(t_llist *list);
int		is_built_in(char *str);

int		assign_command_path(t_llist *list, char **env);
int		check_path(t_llist *list, char **env);
int		is_valid_command(t_node *node);

int		run(t_llist *list, char **env);

