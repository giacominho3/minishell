/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:56:41 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/09 03:56:51 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_TYPES_H
# define ENV_TYPES_H

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

#endif
