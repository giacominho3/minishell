#include "incl/pipeline.h"

int	execute(t_cmd **cmd_head)
{
	int	fd[2]; //fd[0] reads | fd[1] writes

	if (pipe(fd))
		return (1);


}

void	pipe_manager(t_main *main)
{
	if (cont_cmd_number(&main->cmd_head))
	{
		execute(&main->cmd_head);
	}
}
