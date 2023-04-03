/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:58:30 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/09 03:58:41 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_TYPES_H
# define EXPORT_TYPES_H
# include "../../../incl/minishell.h"

typedef struct s_export
{
	char			*name;
	char			*content;
	struct s_export	*next;
	struct s_export	*prev;
}	t_export;

#endif
