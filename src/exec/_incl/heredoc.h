/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:57:16 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/09 03:57:17 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include "../../../incl/minishell.h"

void	heredoc(char *cmd, int index, t_token_list **tok_head);
void	clear_heredoc(t_cmd **cmd_head);

#endif //MINISHELL_HEREDOC_H
