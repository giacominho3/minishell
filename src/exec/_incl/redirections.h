/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:57:28 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/09 03:57:57 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H
# include "../../../incl/minishell.h"

void	ft_heredoc(t_token_list **head, char *limiter);
int		ft_inReidirect(char *cmd, int i);
void	ft_outReidirect(t_token_list **head, char *file);
void	redirections(t_cmd *cmd, int fd[], int *tmp, int proc_type);

#endif
